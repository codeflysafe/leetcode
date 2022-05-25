//
// Created by sjhuang on 2022/5/25.
//

#include "leetcode.h"

class Solution {
public:

    void quickSort(vector<int> &nums, int l, int r, int k){
        if(l == r) return;
        int target = nums[l];
        int start = l ,end = r;
        while(start < end){
            while(start < end && nums[end] >= target){
                end --;
            }
            if(start < end){
                nums[start] = nums[end];
            }
            while(start < end && nums[start] <= target){
                start ++;
            }
            if(start < end){
                nums[end] = nums[start];
            }
        }
        nums[start] = target;
        if(start == k) return;
        else if(start > k){
            quickSort(nums, l, start - 1, k);
        }else {
            quickSort(nums, start + 1, r, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quickSort(nums, 0, n-1, n - k );
        return nums[n-k];
    }
};


int main(){
    Solution sc;
    vector<int> nums = {2,1};
    int k = 2;
    cout << sc.findKthLargest(nums, k);
    return 0;
}