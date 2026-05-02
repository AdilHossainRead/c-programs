/*Given two arrays, greed[] and cookie[] such that greed[i] denotes the minimum cookie size wanted by ith child and cookie[i] denotes the size of ith cookie, we have to find the maximum number of children that can be satisfied by assigning them cookies, with each child getting at most 1 cookie.

Note: A child will be satisfied if he is assigned a cookie of size at least equal to his greed. In other words, the ith child will be satified with jth cookie only if greed[i] <= cookie[j].

Examples:

Input: greed[] = [1, 10, 3], cookie[] = [1, 2,3]
Output: 2
Explanation: We can only assign  cookie to the first child and third child.

Input: greed[] = [10,100], cookie[] = [1, 2]
Output: 0
Explanation: We can not assign cookies to children.*/
#include<stdio.h>

int findContentChildren(int greed[], int gSize, int cookie[], int sSize) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cookie[i] > cookie[i + 1]) { // Descending order
                int temp = cookie[i];
                cookie[i] = cookie[i + 1];
                cookie[i + 1] = temp;

                int temp = greed[i];
                greed[i] = greed[i + 1];
                greed[i + 1] = temp;
            }
        }

    int child_i = 0;
    int cookie_j = 0;
    while (child_i < gSize && cookie_j < sSize) {
        if (cookie[cookie_j] >= greed[child_i]) {
            child_i++;
        }
        cookie_j++;
    }

    }



int main()
{
    int greed[]={1,10,3};
    int cookie[]={1,2,3};
    int gSize = sizeof(greed) / sizeof(greed[0]);
    int sSize = sizeof(cookie) / sizeof(cookie[0]);

    int result = findContentChildren(greed, gSize, cookie, sSize);
    printf("Maximum satisfied children: %d\n", result);
}
