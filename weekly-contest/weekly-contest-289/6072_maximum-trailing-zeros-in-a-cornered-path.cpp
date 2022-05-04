//
// Created by sjhuang on 2022/4/17.
//

#include "leetcode.h"

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // 第一次。 第二次
        vector<vector<vector<vector<int>>>> dp0(m, vector<int>(n, vector<int>(2,1)))
        , dp1(m, vector<int>(n, vector<int>(2,1)));
        dp0[0][0][0] = dp0[0][0][1] = grid[0][0];
        // 竖直方向
        for(int i = 1; i < m; i++){
            dp0[i][0][1] = dp0[i-1][0][1] * grid[i][0];
        }
        // 水平方向
        for(int i = 1; i < n; i++){
            dp0[0][i][0] = dp0[i][i-1][0] *grid[0][i];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                // 第0次
               dp0[i][j][0] =  dp0[i-1][j][0]*grid[i][j];
               dp0[i][j][1] =  dp0[i][j-1][0]*grid[i][j];
               // todo 比较
               dp1[i][j][0] =  dp0[i][j-1][1]*grid[i][j], dp1[i][j-1][0]*grid[i][j];
               dp1[i][j][1] =  dp0[i][j-1][1]*grid[i][j], dp1[i-1][j][1];
            }
        }
    }
};

intr main(){
    return 0;
}