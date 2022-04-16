//
// Created by sjhuang on 2022/3/19.
//

#ifndef LEETCODE_LEETCODE_H
#define LEETCODE_LEETCODE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <set>
#include <map>
#include <stack>

using namespace  std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //LEETCODE_LEETCODE_H
