#include<stdio.h>
#include<string.h>
void main() {
char data[100] = "Data";
char field[100] = "Science";
int pos;
strncpy(data, field, 3);
printf("data1: %s\n", data);
for(pos = 0; data[pos] != '\0'; pos++)
data[pos] += 4;
strncat(field, data, 2);
printf("Data: %s\n", data);
field[pos - 1] = '\0';
printf("Field: %s\n", field);
for(pos = 2; pos > 0; pos--)
strrev(field);
printf("Final Output: %s", field);
}
