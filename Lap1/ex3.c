#include <stdio.h>
#include <math.h>
//The complexity of my program: O(n)
//Change max value
void findMax(int *max,int a){
    *max = a;
}
int main(){
    int n, max;
    printf("Input size of array: \n");
    scanf("%d",&n);
    int Array[n];
    printf("Input elements: \n");
    for (int i=0;i<n;i++){
        scanf("%d",&Array[i]);  
    }
    max = Array[0];
    for (int i=1;i<n;i++){
        if (max<Array[i])
            findMax(&max,Array[i]);
    }
    printf("max = %d",max);
    return 0;
}