/*Given an amount, find the minimum number of notes of different denominations that sum up to the given amount. Starting from the highest denomination note, try to accommodate as many notes as possible for a given amount. We may assume that we have infinite supply of notes of values {2000, 500, 200, 100, 50, 20, 10, 5, 1}
Examples:

Input : 800
Output : Currency  Count
         500 : 1
         200 : 1
         100 : 1

Input : 2456
Output : Currency  Count
         2000 : 1
         200 : 2
         50 : 1
         5 : 1
         1 : 1*/
#include <stdio.h>

void countCurrency(int amount) {
    int notes[] = {2000, 500, 200, 100, 50, 20, 10, 5, 1};
    int n = 9;
    int noteCounter[9] = {0};

    printf("Currency Count \n");
    printf("--------------\n");

    for (int i = 0; i < n; i++) {
        if (amount >= notes[i]) {
            noteCounter[i] = amount / notes[i];

            amount = amount % notes[i];

            printf("%d : %d\n", notes[i], noteCounter[i]);
        }
    }
}

int main() {
    int amount1 = 800;
    printf("Input: %d\n", amount1);
    countCurrency(amount1);

    printf("\n");

    int amount2 = 2456;
    printf("Input: %d\n", amount2);
    countCurrency(amount2);

    return 0;
}
