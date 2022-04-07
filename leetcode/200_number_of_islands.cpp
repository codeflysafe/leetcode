//
// Created by sjhuang on 2022/4/2.
//

#include "leetcode.h"

// dfs
class Solution {
public:

    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n){
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1') return;
        grid[x][y] = 'A';
        dfs(grid, x + 1, y, m, n);
        dfs(grid, x - 1, y, m, n);
        dfs(grid, x , y - 1, m, n);
        dfs(grid, x , y + 1, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans ++;
                    dfs(grid,i, j, m, n);
                }
            }
        }

        return ans;

    }
};

int main(){
    Solution sc;
    vector<vector<char>> grids = { {'1','1'}};
    cout << sc.numIslands(grids);
    return 0;
}