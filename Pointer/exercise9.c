/*Write a C program that declares an integer variable 'num' and initializes it with 5. Declare a pointer
variable and assign the address of 'num' to it. Use the pointer to increment the value of 'num' by 10.
Print the value of 'num' using both the pointer and the variable itself.
Example:
Output: Using variable: 15, Using pointer: 15*/

#include <stdio.h>

int main() {
    int num = 5;      // Declare and initialize the integer variable 'num'
    int *ptr;         // Declare a pointer variable

    ptr = &num;       // Assign the address of 'num' to the pointer

    *ptr += 10;       // Increment the value of 'num' by 10 using the pointer

    // Print the value of 'num' using both the variable and the pointer
    printf("Using variable: %d\n", num);
    printf("Using pointer: %d\n", *ptr);

    return 0;
}
