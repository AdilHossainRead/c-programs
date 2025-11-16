
#include <stdio.h>
// pointer increment and decrement
int main()
{
	int a = 22;
	int *p = &a;
	printf("p = %d\n", *p);
	printf("p = %d\n", p); // p
	p++;
	printf("p++ = %d\n", p); //p++ = p+4 // 4 bytes
	p--;
	printf("p-- = %d\n", p); //p-- = p-4 // restored to original value

	char c = 'a';
	char *r = &c;
	printf("r = %d\n", r); //r
	r++;
	printf("r++ = %d\n", r); //r++ = r+1 // 1 byte
	r--;
	printf("r-- = %d\n", r); //r-- = r-1 // restored to original value

	return 0;
}
