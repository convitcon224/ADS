#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct car
{
    char name[50];
    int pp;
    struct car *next;
};

typedef struct car car;

void printCar(car *node){
    car *temp = node;
    int i=1;
    while (temp!=NULL){
        printf("%d. Car %s has %d passenger(s)\n",i,temp->name,temp->pp);
        temp=temp->next;
        i++;
    }
}

void newNode(car **oldHead){
    car *head = (car*)malloc(sizeof *head);
    printf("Enter car's name: ");
    fflush(stdin);
    gets(head->name);
    printf("Number of passenger(s): ");
    scanf("%d",&(head->pp));
    head->next = *oldHead;
    *oldHead = head;
}

void updateNode(car **node,int *size){
    int n=0;
    printf("Number of new car(s): ");
    scanf("%d",&n);
    while (n<=0){
        printf("Number of new car(s) must be positive\n");
        printf("Number of new car(s): ");
        scanf("%d",&n);
    }
    for (int i=0;i<n;i++){
        newNode(node);
    }
    *size += n;
}

//Remove node when #passenger negative
void removeNode(car **node, int *size){
    car *check = *node;
    int size_c = 1;

    //Head is negative
    while (check->pp <= 0)
    {
        if (*size>1){
            free(check);
            check = check->next;
            *node = check;
            *size -= 1;
        }
        else{
            printf("Must have at least 1 car containing at least 1 person\n");
            exit(0);
        }
    }

    //Body negative
    for(int i=0;i<=*size;i++){
        size_c = 1;
        check = *node;
        while (check!=NULL){
            if(size_c<*size){   
                if(check->next->pp <= 0){
                    free(check->next);
                    check->next=check->next->next;
                    *size -= 1;
                }
            }
            check = check->next;
            size_c++;
        }
    }
}



int main(){
    int size=0;
    car *head = NULL;
    int Answer;

    updateNode(&head,&size);
    // printf("size = %d",size);
    removeNode(&head,&size);
    printCar(head);

   

    while (size>0)
    {
        printf("\nEnter 1 to print length of the train\n");
        printf("Enter 2 to print all cars's information\n");
        printf("Enter 3 to add new car(s)\n");
        printf("Enter 4 to exit\n");
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
            printf("The length of the train is %d\n",size);
            break;
        case 2:
            printCar(head);
            break;
        case 3:
            updateNode(&head,&size);
            removeNode(&head,&size);
            break;
        case 4:
            return 0;
            break;
        }
    }
    return 0;
}