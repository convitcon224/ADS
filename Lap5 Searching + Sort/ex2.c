#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//I chose doubly linked list because it can go back and next easily
//And it also have NULL at both head and tail --> know when to stop and go back

unsigned int size = 0;

struct student{
    char name[40];
    unsigned int index;
    struct student *next, *back;
};

typedef struct student st;


void input(st *stu){
    printf("Enter student order: ");
    scanf("%u",&(stu->index));
    printf("Enter student name: ");
    fflush(stdin);
    gets(stu->name);
}

void newSt(st **head){
    st *newSt = (st*)malloc(sizeof *newSt);

    //use for pointer to head.back
    st *term;
    term = *head;

    input(newSt);

    if(term != NULL){
        newSt->next = term;
        newSt->back = NULL;
        term->back = newSt;
        term = newSt;
        *head = term;
        size ++; 
    }
    else{
        newSt->next = *head;
        newSt->back = NULL;
        *head = newSt;
        size ++;
    }

}


void print(st *stu){
    st *term;
    term = stu;
    while(term!=NULL){
        printf("%u. %s\n",term->index,term->name);
        term = term->next;
    }
}

//Sort
void swap(st **head, st **nex){
    st *a, *b, *prea, *afb;
    a = *head;
    prea = a->back;
    b = *nex;
    afb = b->next;
    
    if(prea != NULL)
        prea->next = b;
    if(afb != NULL)
        afb->back = a;

    a->next = afb;
    b->back = prea;
    b->next = a;
    a->back = b;

}


void sort(st **head){
    bool check = true; //end loop when sorted
    st *stu;
    stu = *head;



    while(check){
        check = false;
        while(stu->next != NULL){
            if(stu->index > stu->next->index){
                swap(&stu,&(stu->next));
                stu = stu->back;
                check = true;
            }
            stu = stu->next;
        }
        while(stu->back != NULL){
            if(stu->index < stu->back->index){
                swap(&(stu->back),&stu);
                stu = stu->next;
                check = true;
            }
            stu = stu->back;
        }
    }
    *head = stu;
}

//End sort

int main(){
    st *head = NULL;
    int Answer=22042000;
    

    printf("Enter first student information:\n");
    newSt(&head);

    while(size>=0){
        printf("\nEnter 1 to print all student(s)\n");
        printf("Enter 2 to add more student(s)\n");
        printf("Enter 3 to sort the list\n");
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
            print(head);
            break;
        case 2:
            newSt(&head);
            break;
        case 3:
            sort(&head);
            break;
        case 4:
            return 0;
        }
    }
}