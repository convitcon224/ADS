#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to fill an array with prime numbers from 1 to n
void fillWithPrimes(int n, int primeArray[]) {
    int index = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primeArray[index] = i;
            index++;
        }
    }
}

int main() {
    int n1, n2;
    printf("Input number #1: ");
    scanf ("%d", &n1);
    printf("Input number #2: ");
    scanf ("%d", &n2);

    int n = (n1 > n2) ? n1 : n2;

    int primeFrom1toN[n];
    fillWithPrimes(n, primeFrom1toN);

    for (int i = 0; i < n; i++) {
        if (primeFrom1toN[i] != 0) {
            printf("Prime number: %d\n", primeFrom1toN[i]);
        }
    }

    return 0;
}
