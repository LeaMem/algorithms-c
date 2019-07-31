//
// Created by iceli on 2019/8/1.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char * getWorlds(char * S){
    int len = strlen(S) + 5;
    char * stack = calloc(len, sizeof(char));
    int top = -1;
    for(int i = 0; i < strlen(S); i++){
        if(S[i] == '#'){
            if(top >= 0){
                top--;
            }
        }else{
            stack[++top] = S[i];
        }
    }
    stack[++top] = '\0';

    return stack;
}

bool backspaceCompare(char * S, char * T){

    char * first = getWorlds(S);
    char * second = getWorlds(T);

    bool ans = strcmp(first, second) == 0;

    free(first);
    free(second);

    return ans;
}

int main(){
    bool ans = backspaceCompare("ab#c", "ad#c");

    return 0;
}