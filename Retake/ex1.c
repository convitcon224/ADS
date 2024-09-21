#include <stdio.h>
#include <math.h>

/*Pseudo code
    function cal(n,ln2,times){
        step = pow(-1,n-1)/n
        if (n=1)
            print ln2 + step
        if (n>1)
            cal(n-1,ln2+step,times)
    }
*/

/*
Complexity:
Best scenario: O(n)
Average: O(n)
Worst scenario: O(n)
Because we always have to go from n to 1
*/



double cal(int n, double sum, int total){
    double step = pow(-1,n-1)/n;

    if (n==1){
        printf("ln2 with n = %d is %lf",total,sum + 1);
    }
    else if (n>1){
        return cal(n-1,sum+step,total);
    }
}

int main(){
    int n;
    printf("Input n: ");
    scanf("%d",&n);
    cal(n,0,n);
}