#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Complexity: O(n)


int main(){
    unsigned long long int n;
    int sum = 0, length = 0;
    printf("Enter a positive number to calculate the digit sum: ");
    scanf("%llu",&n);


    //Find length
    unsigned long long int k = n;
    while (k!=0){
        length += 1;
        k /= 10;
    }

    //Calculate digit sum
    for(int i=0;i<length;i++){
        sum += n%10;
        n /= 10;
    }

    printf("Your results: ");
    printf("%d",sum);
}