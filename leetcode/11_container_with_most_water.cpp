//
// Created by sjhuang on 2022/4/7.
//

#include "leetcode.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 双指针操作
        int n = height.size();
        int l = 0, r = n - 1;
        int ans = 0, cur = 0;
        while (l < r){
            // 当前的容器大小
            cur = min(height[l], height[r]) * (r - l);
            ans = max(cur, ans);
            // 如何更新下一步呢？
            // 将高度低一点的往里移动，这样子才可能超过当前的容量
            if(height[l] < height[r]){
                l ++;
            }else {
                r--;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sc;
    cout << sc.maxArea(height) << endl;
    return 0;
}