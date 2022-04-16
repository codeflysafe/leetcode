//
// Created by sjhuang on 2022/4/16.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "leetcode.h"

class Solution {
public:

//    static bool  cmp1(vector<int> a,vector<int> b){
//       if(a[0] != b[0]) return a[0] < b[0];
//       else return a[1] < b[1];
//   }
    bool isIn(vector<int> a, vector<int> b){
       if(a[1] < b[0] || a[0] > b[1]) return false;
       return true;
    }

    int joinNum(vector<int> a, vector<int> b, vector<int> &orders){
        return rangeCount(orders, a[0], a[1]) + rangeCount(orders, b[0], b[1]) - rangeCount(orders, min(a[0], b[0]),max(b[1], a[1]) );
    }

    void inorder(TreeNode* root, vector<int> &orders){
       if(root){
        inorder(root->left, orders);
        orders[root->val] = 1;
        inorder(root->right, orders);
      }
   }

   int rangeCount(vector<int> &orders, int left, int right){
       if(left == 0) return orders[right];
       else return orders[right] - orders[left-1];
   }


    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
       // 跟二叉树没有关系
       // ops = [[1,2,4],[1,1,3],[0,3,5]]
       int ans = 0;
       vector<int> orders(100001, 0);
       inorder(root, orders);
       int n = orders.size();
       for(int i = 1; i < n; i++){
           orders[i] += orders[i-1];
       }
       map<vector<int>, int> s;
       for(vector<int> op: ops){

           if(op[0] == 1){
               ans += rangeCount(orders,op[1], op[2] );
               if(s.empty()) s[{op[1],op[2]}] = 1;
               else{
                   // 如果包含，
                   vector<int> b = {op[1], op[2]};
                   while(!s.empty()){
                       // 查找有交集的
                       auto it = s.lower_bound(b);
                       if(it != s.end()){
                           if(isIn(it->first, b)){
                               ans -= joinNum(it->first, b, orders);
                               b[0] = min(b[0], it->first[0]);
                               b[1] = max(b[1], it->first[1]);
                               s.erase(it);
                           }
                       }else{
                           it--;
                           if(isIn(it->first, b)){
                               ans -= joinNum(it->first, b,orders);
                               b[0] = min(b[0], it->first[0]);
                               b[1] = max(b[1], it->first[1]);
                               s.erase(it);
                           }else{
                               break;
                           }
                       }
                   }
                   s[b] = 1;
               }
           }else{
               if(s.empty()) continue;
               else{
                   // 如果包含，
                   vector<int> b = {op[1], op[2]};
                   while(!s.empty()){
                       // 查找有交集的
                       auto it = s.lower_bound(b);
                       if(it != s.end()){
                           if(isIn(it->first, b)){
                               ans -= joinNum(it->first, b,orders);
                               b[0] = min(b[0], it->first[0]);
                               b[1] = max(b[1], it->first[1]);
                               s.erase(it);
                           }
                       }else {
                           it--;
//                           vector<vector<int>> res;
                           if(isIn(it->first, b)){
                               ans -= joinNum(it->first, b,orders);
                               if(it->first[0] < b[0] && it->first[1] > b[1]){
                                   s[{it->first[0], b[0] - 1}] = 1;
                                   s[{b[1] + 1, it->first[1]}] = 1;
                               }else if(it->first[0] < b[0] && it->first[1] <= b[1]){
                                   s[{it->first[0], b[0] - 1}] = 1;
                               }else if(it->first[0] >= b[0] && it->first[1] > b[1]){
                                   s[{b[1] + 1, it->first[1]}] = 1;;
                               }
                               s.erase(it);
                           }else{
                               break;
                           }
                       }
                   }
               }
           }
       }


       return ans;


    }
};

int main(){
    Solution sc;
    TreeNode *node = new TreeNode(1);
    node->right = new TreeNode(2);
    node->right->right = new TreeNode(3);
    node->right->right->right = new TreeNode(4);
    node->right->right->right->right = new TreeNode(5);
    vector<vector<int>> ops = {{1,2,4},{1,1,3},{0,3,5}};
    cout << sc.getNumber(node,ops) << endl;
    return 0;
}