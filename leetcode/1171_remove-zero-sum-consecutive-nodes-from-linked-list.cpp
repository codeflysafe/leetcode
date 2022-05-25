//
// Created by sjhuang on 2022/5/25.
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sums;
        ListNode *prev = new ListNode(0);
        sums[0] = prev;
        prev->next = head;
        int prevSum = 0;
        while(head){
            prevSum += head->val;
            if(sums.count(prevSum) != 0) {
                // 删除
                ListNode *cur = sums[prevSum]->next;
                int sum = prevSum;
                while(cur && cur != head){
                    // return cur;
                    sum += cur->val;
                    sums.erase(sum);
                    cur = cur->next;
                }
                sums[prevSum]->next = head->next;
            }else{
                sums[prevSum] = head;
            }
            head = head->next;
        }
        return prev->next;
    }

    // 1,2,3,-3,-2,-3,-2
    // 1,3,6,3,1,-2, -4

    // 1-> 6 -> 7

    // 1,4,6,3,1,6,11,6,7
};

int main(){
    Solution sc;
    sc.removeZeroSumSublists();
    return 0;
}