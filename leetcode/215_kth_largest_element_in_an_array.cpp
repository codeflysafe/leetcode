//
// Created by sjhuang on 2022/4/2.
//
#include "leetcode.h"

class Solution {
public:

    void qucikSort(vector<int> &nums, int l, int r, int k){
        if(l >= r) return;
        // 每次都选择最左边
        int partation = nums[l];
        int start = l , right = r;
        while(start < right){
            while(start < right && nums[right] >= partation){
                right--;
            }
            nums[start] = nums[right];
            while(start < right && nums[start] <= partation){
                start ++;
            }
            nums[right] = nums[start];
        }
        nums[start] = partation;
        if(start == k ) return;
        else {
            if(start > k ){
                qucikSort(nums, l, start-1, k);
            }else{
                qucikSort(nums, start + 1, r, k);
            }
        }

    }

    int findKthLargest(vector<int>& nums, int k) {
        // heap
        int n = nums.size();
        qucikSort(nums, 0, n - 1, n - k);
        return nums[n - k];
    }
};

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution sc;
    cout << sc.findKthLargest(nums, k);
    return 0;
}
