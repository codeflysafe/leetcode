//
// Created by sjhuang on 2022/5/5.
//

#include "leetcode.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 0 || k == 0) return 0;
        int l = 0, r = 0;
        long long cur = nums[0];
        int ans = 0;
        while (r < n){
            // 向后一步，知道不符合条件
            while (r < n && cur < k){
                r ++;
                if(r < n) cur = cur * nums[r];
            }
            if(r == n){
                ans += (r - l)*(r - l + 1)/2;
                break;
            }else if(l == r){
                l ++;
                r ++;
                if(r < n) cur = nums[r];
            }else {
                ans += r - l ;
                cur /= nums[l];
                l ++;
            }
        }
        return ans;
    }
};
int main(){
    Solution sc;
    vector<int> nums{10,2};
    cout << sc.numSubarrayProductLessThanK(nums, 10) << endl;
    return 0;
}