//
// Created by sjhuang on 2022/5/5.
//

#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorder(TreeNode* root, vector<int> &nodes){
        if(root){
            inorder(root->left, nodes);
            nodes.push_back(root->val);
            inorder(root->right, nodes);
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);
        // merge sort
        vector<int> ans;
        int l1 =0, r1 = nums1.size(), l2 = 0, r2= nums2.size();
        while(l1 < r1 && l2 < r2){
            if(nums1[l1] < nums2[l2]){
                ans.push_back(nums1[l1]);
                l1++;
            }else{
                ans.push_back(nums2[l2]);
                l2++;
            }
        }
        while(l1 < r1 ){
            ans.push_back(nums1[l1]);
            l1++;
        }

        while(l2 < r2 ){
            ans.push_back(nums2[l2]);
            l2++;
        }

        return ans;
    }
};


int main(){
    TreeNode *root1 = new TreeNode(2), *root2 = new TreeNode(1);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);
    Solution sc;
    sc.getAllElements(root1,root2);
    return 0;
}