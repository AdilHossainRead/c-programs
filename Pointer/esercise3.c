#include <stdio.h>
int main()
{
    char str[20]="United Int Uni";
    *(str+3) = 'c'; //Updating

    printf("Using pointer: %c\n", *(str+3));
    printf("Using array indexing: %c\n", str[3]);
    return 0;
}
