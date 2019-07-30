//
// Created by 崔进 on 2019-07-25.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "include/node.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {

    if(!head || !head->next){
        return NULL;
    }

    struct ListNode * fast, *slow;

    fast = slow = head;

    while(fast){

        slow = slow->next;

        fast = fast->next;

        if(!fast){
            return NULL;
        }

        fast = fast->next;

        if(fast == slow){
            slow = head;
            break;
        }
    }

    while(slow != fast && fast){
        slow = slow->next;
        fast = fast->next;
    }


    return fast;
}

int main(){

    struct ListNode last = {-4, &last};

    struct ListNode third = {0, &last};

    struct ListNode second = {2, &third};

    struct ListNode root = {1, &second};

    second.next = &root;

    struct ListNode * tmp = detectCycle(&root);



    return 0;
}