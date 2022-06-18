//
// Created by sjhuang on 2022/5/28.
//

#include "leetcode.h"

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // 每个城市的度
        vector<int> D(n, 0);
        for(vector<int> road: roads){
            D[road[0]] ++;
            D[road[1]] ++;
        }
        // 按照大小排序
        sort(D.begin(), D.end(), greater<int>());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += (n-i) * D[i];
        }
        return ans;

    }
};