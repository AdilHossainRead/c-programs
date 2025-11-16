#include<stdio.h>
struct books
{
    char book_name[50];
    char autor[50];
    char group;
    int book_id;
}book3,book4;
int main()
{
    struct books book1,book2;
    strcpy(book1.book_name,"C programming");
    strcpy(book1.autor,"Md Numan Ali");
    book1.group='A';
    book1.book_id=1234;

    printf("Books1 name is :%s \n",book1.book_name);
    printf("Books1 Autor is :%s \n",book1.autor);
    printf("Book group is %d\n",book1.book_id);
    printf("Book group is %c\n",book1.group);


    struct books book3={"Islamic PDF","Arif Azad",'B',2233};
    printf("Books1 name is :%s \n",book3.book_name);
    printf("Books1 Autor is :%s \n",book3.autor);
    printf("Book group is %c\n",book3.group);
    printf("Book group is %d\n",book3.book_id);




}
