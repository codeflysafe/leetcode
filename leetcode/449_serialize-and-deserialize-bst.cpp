//
// Created by sjhuang on 2022/5/11.
//
#include "leetcode.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root){
            string ans = "";
            if(root->left){
                ans += "(" + serialize(root->left) +")";
            }
            ans += to_string(root->val);
            if(root->right){
                ans += "(" + serialize(root->right) + ")";
            }
            return ans;
        }
        return "";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        int left = 0, i = 0, j = 0, val = 0;
        // find 中间值
        for(i = 0; i < n; i++){
            if(i == 0 && data[i] != '('){
                j = i;
                while(j < n && data[j] != '('){
                    val = val * 10 + (data[j] - '0');
                    j++;
                }
                break;
            }else if(data[i] == '('){
                left ++;
            }else if(data[i] == ')'){
                left --;
                if(left == 0){
                    j = i + 1;
                    while(j < n && data[j] != '('){
                        val = val * 10 + (data[j] - '0');
                        j++;
                    }
                    break;
                }
            }
        }
//        cout << i << j << val << data <<  endl;
        TreeNode *node = new TreeNode(val);
        if(i > 0){
            node->left = deserialize(data.substr(1, i-1));
        }
        if(j < n){
            node->right =  deserialize(data.substr(j+1, n-j-2));
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

int main(){
    Codec* ser = new Codec();
    Codec* deser = new Codec();
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    string tree = ser->serialize(root);
    cout << tree << endl;
    TreeNode* ans = deser->deserialize(tree);
    cout << ans->val << endl;
    return 0;
}