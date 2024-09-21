#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

unsigned int size; //Array sz
unsigned int max; //Max array value
int higt = 0; //Height of tree
int nodeNum = 0; //Number of nodes
int maxNodeNum = 0; //Maximum number of nodes
bool end = false; //End loop insert

struct tree{
    int val;
    int lv;
    struct tree *pLeft;
    struct tree *pRight;
    struct tree *parent;
};

typedef struct tree tree;


void arrayMax(int Array[]){
    max = Array[0];
    for (int i = 0;i<size;i++){
        if (max<Array[i])
            max = Array[i];
    }
}

void maxNdNum(){
    maxNodeNum = 0;
    for (int i = 0; i < higt; i++)
        maxNodeNum += pow(2,i);
}

bool isLeaf(tree *p){
    if (p->pLeft == NULL && p->pRight == NULL)
        return 1;
    else
        return 0;
}

//Build branches
void branch(int height, tree *parent, int level){
    //End loop
    if(level > height)
        return;

    tree *newL = (tree *)malloc(sizeof *newL);
    tree *newR = (tree *)malloc(sizeof *newR);
    
    //Left
    parent->pLeft = newL;
    newL->parent = parent;
    newL->pLeft = newL->pRight = NULL;
    newL->lv = level;

    //Right
    parent->pRight = newR;
    newR->parent = parent;
    newR->pLeft = newR->pRight = NULL;
    newR->lv = level;

    //Update
    nodeNum += 2;

    //Loop create tree
    branch(height,newL,level+1);
    branch(height,newR,level+1);
}

//Build tree
void build(unsigned int n, tree **p){
    printf("Building tree for %u values\n",n);

    //init
    tree *curr = (tree*)malloc(sizeof *curr);
    curr->lv = 1;
    curr->pLeft = curr->pRight = *p;
    curr->parent = *p;
    *p = curr;
    nodeNum = 1;

    branch(higt,curr,2);
}

//Assign value for leaves
void asVal(tree *curr, int height, int Array[], int *x){
    if(curr == NULL)
        return;
    if(curr->lv == height && *x>=size)
        curr->val = max + 1;
    else if(curr->lv == height){
        curr->val = Array[*x];
        *x+=1;
    }
    else
        curr->val = 0;

    asVal(curr->pLeft,height,Array,x);
    asVal(curr->pRight,height,Array,x);
}

//Assign value branches
void asValBranches(tree *curr){
    if(curr->pLeft == NULL)
        return;

    if(curr->pLeft->val > curr->pRight->val)
        curr->val = curr->pRight->val;
    else
        curr->val = curr->pLeft->val;

    asValBranches(curr->pLeft);
    asValBranches(curr->pRight);
}

void updateTree(tree *curr){
    //Left
    if(curr->pLeft == NULL)
        return;
    else{
        if(curr->val>curr->pLeft->val)
            curr->val = curr->pLeft->val;
    }

    //Right
    if(curr->pRight == NULL)
        return;
    else{
        if(curr->val>curr->pRight->val)
            curr->val=curr->pRight->val;
    }

    updateTree(curr->pLeft);
    updateTree(curr->pRight);
}


void insert(tree *curr, int x){
    //Check to insert new level
    if(nodeNum == maxNodeNum){
        higt += 1;
        maxNdNum();
    }

    //Check if added
    if(end)
        return;

    //Left
    if(curr->pLeft != NULL){
        if(curr->pLeft->lv == higt)
            return;
        else
            insert(curr->pLeft,x);
    }
    else{
        tree *new = (tree*)malloc(sizeof *new);
        new->val = x;
        new->lv = higt;
        new->pLeft = new->pRight = NULL;
        new->parent = curr;
        curr->pLeft = new;
        end = true;
        nodeNum += 1;
    }

    //Check again
    if(end)
        return;

    //Right
    if(curr->pRight != NULL){
        if(curr->pRight->lv == higt)
            return;
        else
            insert(curr->pRight,x);
    }
    else{
        tree *new = (tree*)malloc(sizeof *new);
        new->val = x;
        new->lv = higt;
        new->pLeft = new->pRight = NULL;
        new->parent = curr;
        curr->pRight = new;
        end = true;
        nodeNum += 1;
    }  
}

void Remove(tree *curr, int x){
    if(curr == NULL)
        return;

    if(curr->val == x && isLeaf(curr)){
        printf("Replaced value of the leaf with its parent\n");
        curr->val = curr->parent->val;
        return;
    }
    Remove(curr->pLeft,x);
    Remove(curr->pRight,x);
}

//Display
void treeprint(tree *root, int level)
{
        if (root == NULL)
                return;
        for (int i = 0; i < level; i++)
                printf(i == level - 1 ? "|-" : "  ");
        printf("%d\n", root->val);
        treeprint(root->pLeft, level + 1);
        treeprint(root->pRight, level + 1);
}

int search(int x, tree *curr){
    if(curr == NULL)
        return -1;

    if(curr->val == x){
        printf("FOUND\n");
        printf("Node store value x has height %d\n",curr->lv);
        treeprint(curr,curr->lv);
        return 0;
    }
    search(x,curr->pLeft);
    search(x,curr->pRight);
}

int main(){
    tree *root = NULL;
    unsigned int Answer = 22042000;

    //Random an array and assign public value
    unsigned int n = 0;
    printf("Enter number of value: ");
    scanf("%u",&n);
    size = n;
    higt = ceil(log2(n))+1;
    int Array[n];
    for(int i=0;i<size;i++)
        Array[i]=rand()%100;
    maxNdNum();

    //Find max
    arrayMax(Array);
    int in = max;

    //Build tree
    build(n,&root);
    //Assign value
    int x = 0; //Use to assign value
    asVal(root,higt,Array,&x);
    for(int i = 1; i < higt;i++)
        asValBranches(root);

    while (nodeNum>0)
    {
        printf("\nEnter 1 to display tree\n");
        printf("Enter 2 to search a value\n");
        printf("Enter 3 to insert a new node\n");
        printf("Enter 4 to remove a leaf node\n");
        printf("Enter 5 to exit");
        printf("Your choice: ");
        scanf("%d",&Answer);
        while (Answer>4||Answer<1)
        {
            printf("Your choice: ");
            scanf("%d",&Answer);
        }
        
        switch (Answer)
        {
        case 1:
            treeprint(root,0);
            break;
        case 2:
            in = max;
            printf("Enter value to search for: ");
            scanf("%d",&in);
            if(in>max)
                max = in;
            search(in,root);
            in = max;
            break;
        case 3:
            in = max;
            end = false;
            printf("Enter value of new node: ");
            scanf("%d",&in);
            if(in>max)
                max = in;
            insert(root,in);
            for(int i = 1; i < higt;i++)
                updateTree(root);
            in = max;
            break;
        case 4:
            printf("Enter value of node which need to be removed: ");
            scanf("%d",&in);
            Remove(root,in);
            break;
        case 5:
            return 0;
        }
    }
}