//
// Created by sjhuang on 2022/3/30.
//

#include "leetcode.h"

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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode *node = head, *prev = nullptr;
        while(node){
            n ++;
            node = node->next;
        }
        int m = n/k;
        if(m == 0) return head;
        node = head;
        ListNode *dump = new ListNode(-1), *tmp = nullptr, *first = nullptr, *cur;
        // 开始反转
        for(int i = 0; i < m; i++){
            cur = node;
            // k 个
            for(int j = 0; j < k; j++){
                tmp = node->next;
                node->next = prev;
                prev = node;
                node = tmp;
            }
            if(dump->next == nullptr){
                dump->next = prev;
            }else {
                first->next = prev;
            }
            first = cur;
            prev = nullptr;
        }

        first->next = node;
        return dump->next;
    }
};

int main(){
    Solution sc;
    int k = 2;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    sc.reverseKGroup(head, k);
    return 0;
}

