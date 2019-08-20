//
// Created by iceli on 2019/8/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "include/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void recreate(struct TreeNode* root, struct TreeNode * head){
    if(!root){
        return ;
    }

    recreate(root->left, head);
    struct TreeNode *new = malloc(sizeof(struct TreeNode));
    new->left = NULL;
    new->val = root->val;
    head->right = new;
    head = new;
    recreate(root->right, head);
}

struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode *stack[150];
    int top = -1;
//    stack[++top] = root;
//
    struct TreeNode * tmp = root;
    struct TreeNode parent = {0, NULL, NULL};
    struct TreeNode *next = &parent;
    while(root || top >= 0){

        while(tmp){
            stack[++top] = tmp;
            tmp = tmp->left;
        }

        tmp = stack[--top];

        if(tmp->right){
            tmp = tmp->right;
        }

        next->left = NULL;
        next->right = tmp;
        next = next->right;
    }

    return parent.right;

}

int main(){

//    struct TreeNode * root = create();
//
//    struct TreeNode * new = increasingBST(root);
//
//    printf("%d\n", new->val);
int * a = 3;
printf("%d\n", *a);

    return 0;
}

