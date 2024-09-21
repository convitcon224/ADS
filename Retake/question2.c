#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//We should use softed array for best result because there will always have c bigger than a and b


int i=0,j=1,k=2;

struct array
{
    int value;
    struct array *next;
};


typedef struct array array;

void updateA(array **oldHead,int val){
    array *head = (array*)malloc(sizeof *head);
    head->value = val;
    head->next = *oldHead;
    *oldHead = head;
}


int pyTrip(int a,int b,int c,array *head){
    int tempA, tempB, tempC;
    array *arr = head;

    if(pow(b,2)+pow(c,2)==pow(a,2)){
        printf("(%d,%d,%d)\n",c,b,a);
    }

    if(i==9&&j==10&&k==11){
        return 0;
    }

    if(k!=11){
        arr = head;
        k+=1;
        for (int o=0;o<k;o++){
            arr = arr->next;
        }
        tempC = arr->value;
        pyTrip(a,b,tempC,head);
    }
    else if(k==11 && j!=10){
        arr=head;
        j+=1;
        k=j+1;
        for(int o=0;o<j;o++){
            arr = arr->next;
        }
        tempB = arr->value;
        arr=head;
        for(int o=0;o<k;o++){
            arr = arr->next;
        }
        tempC = arr->value;
        pyTrip(a,tempB,tempC,head);
    }
    else if(i!=9 && j==10){
        arr=head;
        i+=1;
        j=i+1;
        k=j+1;
        for(int o=0;o<i;o++){
            arr = arr->next;
        }
        tempA = arr->value;
        arr=head;
        for(int o=0;o<j;o++){
            arr = arr->next;
        }
        tempB = arr->value;
        arr=head;
        for(int o=0;o<k;o++){
            arr = arr->next;
        }
        tempC = arr->value;
        pyTrip(tempA,tempB,tempC,head);
    }
}

int main(){
    array *head = NULL;
    int Array[12] = {4,15,28,45,40,9,53,41,8,17,3,5};
    int size = 12;
    for (int i=0;i<12;i++){
        updateA(&head,Array[i]);
    }
    pyTrip(Array[11],Array[10],Array[9],head);
}