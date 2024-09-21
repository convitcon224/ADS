#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Complexity: O(n)

unsigned long long int digitLength(unsigned long long int n){
    if (n<10)
        return 1;
    return 1+digitLength(n/10);
}

unsigned long long int digitSum(unsigned long long int n){
    if (digitLength(n)==1)
        return n;
    return n%10 + digitSum(n/10);
}

int main(){
    unsigned long long int n;
    printf("Enter a positive number to calculate the digit sum: ");
    scanf("%llu",&n);

    printf("Your results: ");
    printf("%d",digitSum(n));
    return 0;
}