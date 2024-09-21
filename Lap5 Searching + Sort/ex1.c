#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Complexity:
//Best scenario: O(n)
//Average: O(n^2)
//Worst scenario: O(n^2)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int input(int *Array,int size){
    for (int i=0;i<size;i++){
        printf("Enter elements number %d: ",i+1);
        scanf("%d",&Array[i]);
    }
}

int print(int Array[], int size){
    printf("Elements list:\n");
    for (int i=0;i<size;i++){
        printf("%d ",Array[i]);
    }
    printf("\n");
}

int sort(int *Array,int size){
    bool check = true; //end loop when sorted

    while(check){
        check = false;
        for (int k=0;k<size-1;k++){
            if(Array[k]>Array[k+1]){
                swap(&(Array[k]),&(Array[k+1]));
                check = true;
            }
        }
        for (int i=size-1;i>0;i--){
            if(Array[i]<Array[i-1]){
                swap(&(Array[i]),&(Array[i-1]));
                check = true;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int Array[n];
    input(Array,n);
    print(Array,n);
    sort(Array,n);
    print(Array,n);
}