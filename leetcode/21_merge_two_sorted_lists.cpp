//
// Created by sjhuang on 2022/4/9.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "leetcode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *root = new ListNode(-1), *node = root;
        while(list1 || list2){
            if(!list1){
                node->next = list2;
                break;
            }
            else if(!list2) {
                node->next = list1;
                break;
            }else if(list1->val < list2->val){
                node ->next = list1;
                node = node->next;
                list1 = list1->next;
            }else {
                node ->next = list2;
                node = node->next;
                list2 = list2->next;
            }
        }

        return root->next;
    }
};

int main(){
    Solution sc;
//    sc.mergeTwoLists();
    return 0;
}