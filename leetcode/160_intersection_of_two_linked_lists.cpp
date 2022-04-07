//
// Created by sjhuang on 2022/4/2.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "leetcode.h"

class Solution {
public:

    int len(ListNode *node){
        if(node){
            return len(node->next) + 1;
        }
        return 0;
    }

    ListNode *joinNode(ListNode *headA, ListNode *headB, int k){
        for(int i = 0; i < k; i++){
            headA = headA -> next;
        }
        while(headA && headB){
            if(headB == headA) return headA;
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = len(headA), n2 = len(headB);
        if(n1 > n2){
            return joinNode(headA, headB, n1 - n2);
        }else return joinNode(headB, headA, n2 - n1);
    }
};