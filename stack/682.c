//
// Created by iceli on 2019/7/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void getCurrentValue(int *stack, const bool *list, int index, int n) {

    int cnt = 0;
    int tmp = index;

    while (tmp > 0 && cnt < n) {
        if (list[--tmp] == true) {
            cnt++;
            if (n == 1) {
                stack[index] = stack[tmp] * 2;
            } else {
                stack[index] += stack[tmp];
            }
        }
    }

}

int calPoints(char **ops, int opsSize) {

    int ans = 0;

    int *stack = calloc(opsSize, sizeof(int));

    bool *list = calloc(opsSize, sizeof(bool));


    for (int i = 0; i < opsSize; i++) {
        char *cur = ops[i];
        list[i] = true;

        if (strcmp(cur, "+") == 0) {

            getCurrentValue(stack, list, i, 2);

        } else if (strcmp(cur, "D") == 0) {

            getCurrentValue(stack, list, i, 1);

        } else if (strcmp(cur, "C") == 0) {

            list[i] = false;
            for (int j = i - 1; j >= 0; j--) {
                if (list[j] == true) {
                    list[j] = false;
                    break;
                }
            }

        } else {
            sscanf(cur, "%d", &stack[i]);
        }
    }

    for (int i = 0; i < opsSize; i++) {
        if (list[i] == true) {
            ans += stack[i];
        }
    }

    free(list);
    free(stack);

    return ans;

}

int main() {
    char *S[] = {"1", "C", "-62", "-45", "-68"};

    int res = calPoints(S, 5);

    printf("%d\n", res);

    return 0;

}


