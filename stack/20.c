//
// Created by iceli on 2019/8/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool valid(char * stack, int *index, char left){

    if(*index >= 0 && stack[*index] == left){
        (*index)--;
        return true;
    }
    return false;
}

bool isValid(char *s) {
    int len = strlen(s);
    char stack[8000];
    int top = -1;
    for(int i = 0; i < len; i++){

        if(s[i] == ')' && !valid(stack, &top, '(')){
            return false;
        }

        if(s[i] == '}' && !valid(stack, &top, '{')){
            return false;
        }

        if(s[i] == ']' && !valid(stack, &top, '[')){
            return false;
        }

        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            stack[++top] = s[i];
        }
    }


    return top < 0;

}

int main(){

    char *s = "(]";

    bool ans = isValid(s);

    return 0;
}
