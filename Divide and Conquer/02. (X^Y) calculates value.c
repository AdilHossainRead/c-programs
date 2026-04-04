//Problem-2 (X^Y): Write a program that takes X and Y as input and calculates the value of X^Y using
//divide and conquer and prints it.
#include <stdio.h>
long long power(int x, int y) {
    if (y == 0) {
        return 1;
    }

    long long temp = power(x, y / 2);
    if (y % 2 == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}

int main() {
    int x, y;
    printf("Enter base (X): ");
    scanf("%d", &x);
    printf("Enter exponent (Y): ");
    scanf("%d", &y);

    printf("%d^%d = %lld\n", x, y, power(x, y));

    return 0;
}
