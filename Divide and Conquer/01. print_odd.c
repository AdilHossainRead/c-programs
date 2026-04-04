//Problem-1: Write a function print_odd using divide-and-conquer algorithm to print the odd numbers
//of an array of n integers.
#include<stdio.h>
void print_odd(int arr[], int left, int right)
{
    if (left == right) {
        if (arr[left] % 2 != 0) {
            printf("%d ", arr[left]);
        }
        return;
    }
    int mid = left + (right - left) / 2;
    print_odd(arr, left, mid);
    print_odd(arr, mid + 1, right);
}
int main() {
    int arr[] = {10, 15, 22, 37, 45, 50, 63};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Odd numbers in the array: ");
    print_odd(arr, 0, n - 1);
    printf("\n");

    return 0;
}
