//
// Created by sjhuang on 2022/3/27.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:

    int minDeletion(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<int> left;
        int sz = 0;
        // 删除 nums[i]
        while(i < n){
            sz = left.size();
            if(sz % 2 == 1){
                // 当前是奇数
                left.push_back(nums[i]);
            }else{
                // 当前是偶数
                if(i + 1 < n){
                    if(nums[i] != nums[i+1]){
                        left.push_back(nums[i]);
                    }
                }else{
                    left.push_back(nums[i]);
                }
            }
            i++;
        }
        for(int l: left){
            cout << l << " ";
        }
        sz = left.size();
        return n - sz + (sz % 2 == 0?0:1);
    }
};


int main(){
    Solution sc;
    vector<int> nums = {1,1,2,2,3,3};
    sc.minDeletion(nums);
    return 0;
}