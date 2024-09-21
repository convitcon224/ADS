#include <stdio.h>
#include <math.h>

double cal(int n,double sum,int k){
    if (n==0){
        printf("%lf",2/(3-1/sum));
    }
    else if (n>0){
        cal(n-1,3*k-(pow(n,2)/sum),k-2);
    }
}

int main(){
    int n;
    printf("Input n: ");
    scanf("%d",&n);
    cal(n,3*(2*n-1),n*2-1);
}