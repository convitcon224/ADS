#include <stdio.h>
#include <math.h>


int getPrime(int n,int p){
    if(p>n){
        return 0;
    }
    if(n%p==0){
        
    }
}

int getPrimeList(int n,int i){
    if(n%i==0){
        return i;
    }
    return getPrimeList(n,i+1);
}

int main(){
    int n1,n2;
    printf("Input number #1: ");
    scanf ("%d",&n1);
    printf("Input number #2: ");
    scanf ("%d",&n2);
    
    int n = n1;
    if(n1>n2){
        int n = n1;
    }
    else{
        int n=n2;
    }
    int primeFrom1toN[n];

    int k = n;

    for(int i=0;i<n;i++){
        if (i==0){
            primeFrom1toN[i] = getPrimeList(n,2);
            printf("Input number #1: %d\n",primeFrom1toN[i]);
        }
        else{
            primeFrom1toN[i] = getPrimeList(n,primeFrom1toN[i-1]+1);
            printf("Input number #1: %d\n",primeFrom1toN[i]);
        }
    }



    int primeArray1[n1];
    int primeArray2[n2];

    for(int i=0;i<n;i++){
        primeArray1[i] = getPrime(n1,2);
        primeArray2[i] = getPrime(n2,2);
    }

    
    
}