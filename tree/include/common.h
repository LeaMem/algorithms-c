//
// Created by 崔进 on 2019-07-17.
//

#ifndef LEETCODE_C_COMMON_H
#define LEETCODE_C_COMMON_H

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *create();

#endif //LEETCODE_C_COMMON_H
