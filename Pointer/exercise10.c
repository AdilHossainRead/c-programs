/*Write a C program that reads 5 integers from the user and stores them in an array. Use a pointer to
calculate the sum of all the elements in the array. Print the sum.
Example:
Input: 1 2 3 4 5
Output: Sum: 15*/
#include <stdio.h>

int main() {
    int arr[5];     // Array to store 5 integers
    int *ptr;       // Pointer to traverse the array
    int sum = 0;    // Variable to store the sum

    // Reading 5 integers from the user
    printf("Enter 5 integers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Pointer points to the first element of the array
    ptr = arr;

    // Calculating the sum using the pointer
    for (int i = 0; i < 5; i++) {
        sum += *(ptr + i);   // Dereference pointer and add to sum
    }

    // Output the sum
    printf("Sum: %d\n", sum);

    return 0;
}
