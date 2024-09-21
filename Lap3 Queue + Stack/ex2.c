#include <stdio.h>
#include <stdlib.h>

//Toy quantity
int doll = 900;
int superman = 300;
int lamp = 1000;


struct Toy{
    int d;
    int s;
    int l;
    int index;
    struct Toy *next;
};

typedef struct Toy toy;

struct Stack{
    int size;
    toy *top;
};

typedef struct Stack stack;

struct StackRedo{
    int size;
    toy *top;
};

typedef struct StackRedo redo;

//Random quantity
int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int getMin(int a, int b){
    if (a<b)
        return a;
    else
        return b;
}

void init(stack *st, redo *sr){
    st->size = 0;
    st->top = NULL;

    sr->size = 0;
    sr->top = NULL;
}


void display(stack st){
    while(st.top!=NULL){
        if(st.top->d==0&&st.top->s==0&&st.top->l==0)
            printf("\nCustomer number %d buy nothing\n",st.top->index);
        else{
            printf("\nCustomer number %d buys:\n",st.top->index);
            if(st.top->d > 0)
                printf("    %d doll(s)\n",st.top->d);
            if(st.top->s > 0)
                printf("    %d superman(s)\n",st.top->s);
            if(st.top->l > 0)
                printf("    %d lamp(s)\n",st.top->l);
            }
        st.top=st.top->next;
    }
}


void push(stack *st, int dl, int sup, int la){
    toy *p;
    p = (toy *)malloc(sizeof(toy));
    if (p==NULL)
        return;
    p->d = dl;
    p->s = sup;
    p->l = la;
    p->next = st->top;
    st->top=p;
    st->size +=1;
    st->top->index = st->size;
    return;
}


void Redo(stack *st,redo *sr){
    if(sr->size<=0){
        printf("\nNothing to redo\n");
        return;
    }
    toy *p;
    
    p = sr->top;
    p->index = st->top->index + 1;

    //Remove in redo stack
    sr->top = sr->top->next;
    sr->size -= 1;

    //Go to main stack
    p->next = st->top;
    st->top = p;
    st->size += 1;

    //Restore items
    doll -= p->d;
    superman -= p->s;
    lamp -= p->l;

    printf("\nRedo succeed\n");
}


void Undo(stack *st, redo *sr){
    toy *p;
    if (st->top==NULL)
        return;
    p = st->top;

    //Restore items
    doll += p->d;
    superman += p->s;
    lamp += p->l;

    //Remove in main stack
    st->top = st->top->next;
    st->size -= 1;

    //Go to redo stack
    p->next = sr->top;
    sr->top = p;
    sr->size += 1;
    printf("\nUndo succeed\n");
}

//Cus buy
void add(int *dl, int *sup, int *la){
    int b_d=0, b_s=0, b_l=0; //Cus buy
    int d,s,l; //Quantity can buy

    //Number of doll can buy
    if (doll>0)
        d = GetRandom(1,getMin(2,doll));
    else{
        printf("Doll is out of stock\n");
        d=0;
    }
    
    //Number of superman can buy
    if (superman>0)
        s = GetRandom(1,getMin(3,superman));
    else{
        printf("Superman is out of stock\n");
        s = 0;
    }

    //Number of lamp can buy
    if (lamp>0)
        l = GetRandom(1,getMin(4,lamp));
    else{
        printf("Lamp is out of stock\n");
        l=0;
    }

    //Buy products
    printf("\nYou can buy %d doll(s), %d superman(s), %d lamp(s)\n",d,s,l);
    //Buy doll
    if(d!=0){
        printf("How many doll(s) do you want to buy? ");
        scanf("%d",&b_d);
        while (b_d>d||b_d<0)
        {
            printf("You can buy %d doll(s)\n",d);
            printf("How many doll(s) do you want to buy? ");
            scanf("%d",&b_d);
        }      
        if(b_d<=d && b_d>=0){
            printf("Purchase success\n");
            printf("You bought %d doll(s)\n",b_d);
            doll -= b_d;
        }
    }

    //Buy superman
    if(s!=0){
        printf("How many superman(s) do you want to buy? ");
        scanf("%d",&b_s);
        while (b_s>s||b_s<0)
        {
            printf("You can buy %d superman(s)\n",s);
            printf("How many superman(s) do you want to buy? ");
            scanf("%d",&b_s);
        }      
        if(b_s<=s && b_s>=0){
            printf("Purchase success\n");
            printf("You bought %d superman(s)\n",b_s);
            superman -= b_s;
        }
    }
    
    //Buy lamp
    if(l!=0){
        printf("How many lamp(s) do you want to buy? ");
        scanf("%d",&b_l);
        while (b_l>l||b_l<0)
        {
            printf("You can buy %d lamp(s)\n",l);
            printf("How many lamp(s) do you want to buy? ");
            scanf("%d",&b_l);
        }      
        if(b_l<=l && b_l>=0){
            printf("Purchase success\n");
            printf("You bought %d lamp(s)\n",b_l);
            lamp -= b_l;
        }
    }

    //Return items
    *dl = b_d;
    *sup = b_s;
    *la = b_l;
}

//Print items left
void printItem(){
    printf("    \n%d doll(s) left\n",doll);
    printf("    \n%d superman(s) left\n",superman);
    printf("    \n%d lamp(s) left\n",lamp);
}

//Clear redo stack
void Clean(redo *sr){
    while(sr->top!=NULL){
        free(sr->top);
        sr->top=sr->top->next;
    }
    sr->top = NULL;
    sr->size = 0;
    printf("\nClean redo stack succeed\n");
}

int main(){
    int buyDoll, buySup, buyLamp;
    stack customer;
    redo store;

    init(&customer,&store);
    add(&buyDoll,&buySup,&buyLamp);
    push(&customer,buyDoll,buySup,buyLamp);

    int choice = 22042000;


    //Loop
    while (customer.size>0){
        printf("\nEnter 1 for the next customer to buy\n");
        printf("Enter 2 to print all buying history\n");
        printf("Enter 3 to undo last action\n");
        printf("Enter 4 to redo\n");
        printf("Enter 5 to display item status\n");
        printf("Enter 6 to clear redo stack\n");
        printf("Enter 7 to exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        while (choice<1||choice>7)
        {
            printf("Your choice: ");
            scanf("%d",&choice);
        }

        switch (choice)
        {
        case 1:
            add(&buyDoll,&buySup,&buyLamp);
            push(&customer,buyDoll,buySup,buyLamp);
            break;
        case 2:
            display(customer);
            break;
        case 3:
            Undo(&customer,&store);
            break;
        case 4:
            Redo(&customer,&store);
            break;
        case 5:
            printItem();
            break;
        case 6:
            Clean(&store);
            break;
        case 7:
            return 0;
        }   
    }
}