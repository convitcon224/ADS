#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Complexity: O(n^2)


int prime(int n){
    if(n<=2)
        return 2;
    for(int i=2;i<n;i++){
        if(n%i==0)
            return prime(n-1);
    }
    return n;
}


//initial
//check = 0 number of prime number
//n2 = 1 iteration
//repeat = -1 different prime number each time
int sphenic(int n, int check, int n2, int repeat){
    if (n==prime(n) && check == 2 && repeat!=prime(n-n2))
        return 0;
    else if ((n%prime(n-n2))==0 && check<2 && repeat!=prime(n-n2))
        return sphenic(n/prime(n-n2),check+1,1,prime(n-n2));
    else if ((n%prime(n-n2))!=0 && n2<n || (n%prime(n-n2))==0 && n2<n && repeat==prime(n-n2))
        return sphenic(n,check,n2+1,repeat);
    else
        return 1;

}


int main(){
    int n;
    int test = -1;
    int k = 1;

    while (k==1){
        printf("Enter a positive number: ");
        scanf("%d",&n);
        test = sphenic(n,0,1,-1);
        if (test == 0)
            printf("%d is a sphenic number\n",n);
        else if (test == 1)
            printf("%d is not a sphenic number\n",n);
    }
}