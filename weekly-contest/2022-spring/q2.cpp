//
// Created by sjhuang on 2022/4/16.
//

#include <vector>

class Solution {
public:

    int ans = -1;

    // 判断是否满足材料的限制
    bool isvalid(vector<int>& materials, vector<vector<int>>& cookbooks, int t){
        vector<int> cookbook = cookbooks[t];
        for(int i = 0; i < 5; i++){
            if(cookbook[i] > materials[i]){
                return false;
            }
        }
        for(int i = 0; i < 5; i++){
            materials[i] -= cookbook[i];
        }
        return true;
    }

    // backtrace
    void backtrace(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute,int lm, int limit, int delicious , int i, int n){
        if(lm >= limit)  {
            ans = max(ans, delicious);
        }
        if(i >= n) return;
        for(int j = i; j < n; j++){
            vector<int> ms = materials;
            // 满足条件
            if(isvalid(materials, cookbooks, j)){
                backtrace(materials, cookbooks, attribute, lm + attribute[j][1], limit, delicious + attribute[j][0], j + 1, n);
                materials = ms;
            }
        }
    }

    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        backtrace(materials,cookbooks,attribute,0,limit,0,0,attribute.size());
        return ans;
    }
};