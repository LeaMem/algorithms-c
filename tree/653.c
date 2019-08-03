//
// Created by iceli on 2019/8/1.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "include/common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct Node{
    int key;
    int rest;
}Node;


bool find(struct TreeNode * root, Node * node, int *index, int target){

    if(!root){
        return false;
    }

    bool ansL = find(root->left, node, index, target);


    int rest = target - root->val;
    for(int i = 0; i < *index; i++){
        if(node[i].rest == rest){
            return true;
        }
    }

    Node tmp = {root->val, rest};
    node[++(*index)] = tmp;


    bool ansR = find(root->right, node, index, target);

    return ansL || ansR;

}

bool findTarget(struct TreeNode* root, int k){
    Node node[8000];
    int index = -1;


    return find(root, node, &index, k);
}

