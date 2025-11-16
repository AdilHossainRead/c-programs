/* 6. Write a program (WAP) for the described scenario:
Player-1 picks a number X and Player-2 has to guess that number within N tries. For each
wrong guess by Player-2, the program prints “Wrong, N-1 Choice(s) Left!” If Player-2 at
any time successfully guesses the number, the program prints “Right, Player-2 wins!” and
terminates right away. Otherwise after the completion of N wrong tries, the program
prints “Player-1 wins!” and halts.
(Hint: Use break/continue)
Sample input
(X,N,n1, n2,..,nN)
Sample output
5
3
12 8 5
Wrong, 2 Choice(s) Left!
Wrong, 1 Choice(s) Left!
Right, Player-2 wins!
100
5
50 100
Wrong, 4 Choice(s) Left!
Right, Player-2 wins!
20
3
12 8 5
Wrong, 2 Choice(s) Left!
Wrong, 1 Choice(s) Left!
Wrong, 0 Choice(s) Left!
Player-1 wins!*/
#include<stdio.h>
int main()
{
    int i,n,p1,p2;
    printf("Enter player1 number:");
    scanf("%d",&p1);
    printf("Enter guess number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(i==1){
            printf("Enter %dst choice:",i);
        }else if(i==2){
        printf("Enter %dnd choice:",i);
        }else if(i==3){
        printf("Enter %dnd choice:",i);
        }else{
        printf("Enter %dth choice:",i);
        }
        //printf("Enter the %d choice:",i);
        scanf("%d",&p2);
        if(p1==p2){
            printf("Right, Player-2 wins!\n");
            break;
        }else{
        printf("Wrong, %d Choice(s) Left\n",n-i);
        }if(n-i==0){
        printf("Player-1 wins!\n");
        printf("Player-2 lost the game!\n");
        }
    }
}
