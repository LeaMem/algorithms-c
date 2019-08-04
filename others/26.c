//
// Created by 崔进 on 2019-08-04.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize){
    int len = 0;
    if(numsSize <= 1){
        return numsSize;
    }

    int i = 1;
    int tmp = nums[i - 1];
    while(i < numsSize){

        if(nums[i] == tmp){
            for(int index = i; index < numsSize - 1; index++){
                nums[index] = nums[index + 1];
            }
            numsSize--;
        }else{
            tmp = nums[i];
            i++;
        }

    }

    return i;
}

int main(){

    int nums[10] = {0,0,1,1,1,2,2,3,3,4};
    int ans = removeDuplicates(nums, 10);

    printf("%d\n", ans);

    return 0;

}
