#include <stdio.h>
int counds(char *str) {
    int count = 0,i = 0;
    while (str[i]!='\0') {
        if ((i == 0 || str[i-1] == ' ') && str[i] != ' ') {
            count++;
        }
        i++;
    }
    return count;
}
int midword(char str[]) {
    int wort = counds(str);
    int midex = wort / 2;
    int counds = 0, i = 0;
    while (str[i] != '\0') {
        if ((i == 0 || str[i-1] == ' ') && str[i] != ' ') {
        if (counds == midex) {
        return i;
    }
        counds++;
    }
        i++;
    }
    return -1;
}
int gon(char str[]) {
    int start = midword(str);
    if (start == -1) {
        return 0;
    }
    int end = start;
    while (str[end] != ' ' && str[end] != '\0') {
    end++;
    }
    if (str[start] == '?' && str[end - 1] == '#') {
        for (int i = start + 1; i < end - 1; i++) {
    if (!isalpha(str[i])) {
        return 0;
    }
}
return 1;
}
return 0;
}
int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    if (gon(str)) {
    printf("Yes\n");
    } else {
    printf("No\n");
    }
}
