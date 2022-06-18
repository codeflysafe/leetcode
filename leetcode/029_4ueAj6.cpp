//
// Created by sjhuang on 2022/6/18.
//

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

#include "leetcode.h"
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        // 只有一个节点时
        if(head->next == head){
            head->next = new Node(insertVal);
            head->next->next = head;
            return head;
        }

        // find the correct position
        Node *prev = nullptr, *node = head;
        while(!(prev && ((node->val >= prev->val && insertVal >= prev->val && insertVal <= node->val) ||
                         (node->val < prev->val && insertVal >= prev->val && insertVal > node->val) ||
                         (node->val < prev->val && insertVal < prev->val && insertVal < node->val)))){
            prev = node;
            node = node->next;
            if(node == head){
                break;
            }
        }
        // insert into this position
        prev->next = new Node(insertVal);
        prev->next->next = node;

        return head;
    }
};