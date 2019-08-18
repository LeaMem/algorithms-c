//
// Created by 崔进 on 2019-08-18.
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
struct TreeNode *local(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (!root) {
        return NULL;
    }
    if (p->val <= root->val && root->val <= q->val) {
        return root;
    } else if (root->val <= p->val) {
        return local(root->right, p, q);
    } else {
        return local(root->left, p, q);
    }
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (p->val > q->val) {
        struct TreeNode *tmp = p;
        p = q;
        q = tmp;
    }

    return local(root, p, q);

}

int main(){
    struct TreeNode four = {4, NULL, NULL};
    struct TreeNode two = {2, NULL, &four};
    struct TreeNode root = {6, &two, NULL};

    struct TreeNode * ans = lowestCommonAncestor(&root, &two, &four);

    return 0;
}
