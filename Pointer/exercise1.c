// C program to illustrate Pointers
#include <stdio.h>
int main()
{
	int var = 10;
	// declare pointer variable
	int* ptr;
	// initialize pointer variable (assign address)
	ptr = &var;

	printf("Address of var using & = %d \n",&var);
	printf("Value at var = %d \n", var);
	printf("Address of var stored in ptr = %d \n", ptr);
	printf("Value at var stored in ptr = %d \n", *ptr);

	// dereferencing pointer variable
	int def;
	def = *ptr;
	printf("Value of var by dereferencing ptr = %d \n", def);

	*ptr = 20;
	printf("Value of var by after updating = %d (using *ptr) %d (Using var) \n", *ptr,var);
	return 0;
}

