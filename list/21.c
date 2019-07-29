//
// Created by 崔进 on 2019-07-17.
//


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "include/node.h"
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

int main() {
    struct ListNode* l1 = insertValue();
    printf("kk");

    struct ListNode* l2 = insertValue();

    struct ListNode* res = mergeTwoLists(l1, l2);
    printf("kk");

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode List;
    List start = {0, NULL};
    List* tail = &start;

    List* first = l1;
    List* second = l2;
    while (first || second) {
        if (first && second) {
            if (first->val <= second->val) {
                tail->next = first;
                first = first->next;

            } else {
                tail->next = second;
                second = second->next;
            }

        } else if (first) {
            tail->next = first;
            first = first->next;
        } else {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }
    return start.next;
}