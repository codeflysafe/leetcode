//
// Created by sjhuang on 2022/4/9.
//

#include "leetcode.h"
class Solution {
public:

    int findCloest(vector<int> &nums, int l, int r, int k){
        if(l == r) return nums[l];
        int ans = INT_MAX;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if(nums[m] == k) return k;
            else{
                if(ans == INT_MAX){
                    ans = nums[m];
                }else if(abs(nums[m] - k) < abs(ans-k)){
                    ans = nums[m];
                }
                if(nums[m] > k) r = m - 1;
                else l = m + 1;
            }
        }
        return ans;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        // 1000
        // 排序 / 优先队列
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, sum = 0, n = nums.size();
        for(int i = n-2; i >= 1; i--){
            sum = nums[i];
            for(int j = i-1; j >= 0; j--){
                sum += nums[j];
                int k = target - sum;
                // 最接近k的
                int t  = findCloest(nums, i + 1, n-1,k );
                if(ans == INT_MAX){
                    ans = t + sum;
                }else if(abs(t + sum - target) < abs(ans - target)){
                    ans = t + sum;
                }
                sum -= nums[j];
            }
        }

        return ans;

    }
};

int main(){
    Solution sc;
    vector<int> nums = {1,2,5,10,11};
    int target = 12;
    cout << sc.threeSumClosest(nums, target);
    return 0;
}