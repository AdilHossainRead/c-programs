/*9. WAP that will take n integers into an array A, and then copy all numbers in reverse order
from array A to another array B. Finally show all elements of both array A and B.
Sample input Sample output
8
7 8 1 3 2 6 4 3
Array A : 7 8 1 3 2 6 4 3
Array B : 3 4 6 2 3 1 8 7
3
3 2 1
Array A : 3 2 1
Array B : 1 2 3*/
/*#include<stdio.h>
int main()
{
    int n,i,value,possition=-1;
    printf("Enter the number of array:");
    scanf("%d",&n);
    int array_A[n],array_B[n];
    for(i=0;i<n;i++){
        printf("Enter %d number element:",i);
        scanf("%d",&array_A[i]);
    }
    printf("The character of array A: ");
    for(i=0;i<n;i++){
        printf(" %d",array_A[i]);
    }
    printf("\n");
    printf("array_B= ");
    for(i=n-1;i>=0;i--){
        array_B[i]=array_A[i];
        printf("%d,",array_B[i]);
    }

}*/#include <stdio.h>

void swapArrays(int A[], int m, int B[], int n) {
    // Swap all elements between A and B
    int temp;
    for (int i = 0; i < m && i < n; ++i) {
        temp = A[i];
        A[i] = B[i];
        B[i] = temp;
    }
}

void printArray(int arr[], int size, char *label) {
    printf("%s : ", label);
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");
}

int main() {
    int n, m;

    // Input array A
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    // Input array B
    scanf("%d", &m);
    int B[m];
    for (int i = 0; i < m; ++i) {
        scanf("%d", &B[i]);
    }

    // Swap arrays A and B
    swapArrays(A, n, B, m);

    // Print elements of both arrays
    printArray(A, m, "Array A");
    printArray(B, n, "Array B");

    return 0;
}
