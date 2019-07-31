//
// Created by iceli on 2019/7/31.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char * removeDuplicates(char * S){

    char * stack = calloc(20050, sizeof(char));
    int len = strlen(S);

    int top = -1;

    for(int i = 0; i < len; i++){

        char c = S[i];
        if(top == -1 || stack[top] != c){
            stack[++top] = c;
        }else{
            top --;
        }

    }

    stack[++top] = '\0';

    return stack;
}
