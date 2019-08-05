//
// Created by iceli on 2019/8/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *convertToTitle(int n) {

    char *ans = malloc(sizeof(char) * 1000);
    int index = 0;
    while (n != 0) {
        n--;
        int tmp = n % 26;
        ans[index++] = tmp + 'A';
        n /= 26;
    }


    for (int i = 0; i < index / 2; i++) {
        char swap = ans[i];
        ans[i] = ans[index - i - 1];
        ans[index - i - 1] = swap;
    }

    ans[index++] = '\0';

    return ans;
}

int main() {

    char *res = convertToTitle(52);

    printf("%s\n", res);

    return 0;

}