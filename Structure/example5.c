#include<stdio.h>
struct books
{
    char book_name[50];
    char autor[50];
    char group;
    int book_id;
} book1,book4;
void printbook(struct books book1)
{
    printf("Books1 name is :%s \n",book1.book_name);
    printf("Books1 Autor is :%s \n",book1.autor);
    printf("Book group is %d\n",book1.book_id);
    printf("Book group is %c\n",book1.group);

}
int main()
{
    struct books book2,book3;
    struct books book1= {"C Programming","Md Muhamad Ali",'A',112233};
    printbook(book1);
}
