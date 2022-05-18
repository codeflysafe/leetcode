//
// Created by sjhuang on 2022/5/18.
//

#include "leetcode.h"

class Solution {
public:
    set<vector<int>> ans;

    void backprop(vector<int> &nums, int n, int i, vector<int> &path){
        if(__builtin_popcount(i) == n){
            ans.insert(path);
            return;
        }
        for(int j = 0; j < n; j++){
            if(i >> j){
                continue;
            }else{
                int t = i;
                path.push_back(nums[j]);
                backprop(nums, n, i|(1<<j), path);
                path.pop_back();
                i = t;
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        backprop(nums, n, 0, path);
        vector<vector<int>> res;
        for(vector<int> cur: ans){
            res.push_back(cur);
        }
        return res;
    }
};

int main(){
    Solution sc;
    vector<int> nums = {1,2,3};
    sc.permuteUnique(nums);
    return 0;
}
