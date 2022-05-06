//
// Created by sjhuang on 2022/5/5.
//

#include "leetcode.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = 100001;
        vector<int> paths(n,0);
        for(int num: nums){
            paths[num] = 1;
        }
        int cur = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(paths[i] > 0){
                cur ++;
            }else {
                ans = max(ans, cur);
                cur = 0;
            }
        }
        return ans;
    }
};

int main(){
    Solution sc;
    vector<int> nums {100,4,200,1,3,2};
    cout << sc.longestConsecutive(nums) << endl;
    return 0;
}