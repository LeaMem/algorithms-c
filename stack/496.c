//
// Created by iceli on 2019/7/31.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    *returnSize = nums1Size;
    int * ans = calloc(nums1Size, sizeof(int));

    if(nums1Size <= 0){
        return ans;
    }


    for(int i = 0; i < nums1Size; i++){
        ans[i] = -1;

        bool self = false;
        for(int j = 0; j < nums2Size; j++){

            if(nums2[j] == nums1[i]){
                self = true;
            }

            if(self && nums2[j] > nums1[i]){
                ans[i] = nums2[j];
                break;
            }
        }
    }


    return ans;

}

