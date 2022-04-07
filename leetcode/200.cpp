//
// Created by sjhuang on 2022/4/2.
//

#include "leetcode.h"

class Solution {
public:

    // union and find
    int find(vector<int> &parent, int a){
        if(parent[a] != a){
            parent[a] = find(parent,parent[a]);
        }
        return parent[a];
    }

    void unionF(vector<int> &parent, int a, int b){
        int pa = find(parent, a);
        int pb = find(parent, b);
        if(pa != pb){
            parent[pa] = pb;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m*n, 0);
        for(int i =0; i < m*n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    if(i - 1 >= 0 && grid[i-1][j] == '1'){
                        unionF(parent, i*n + j, (i-1)*n + j);
                    }
                    if(i + 1 < m && grid[i+1][j] == '1'){
                        unionF(parent, i*n + j, (i+1)*n + j);
                    }
                    if(j - 1 >= 0 && grid[i][j-1] == '1'){
                        unionF(parent, i*n + j,  i*n + j - 1);
                    }
                    if(j + 1 < n && grid[i][j+1] == '1'){
                        unionF(parent, i*n + j,  i*n + j + 1);
                    }
                }else{
                    parent[i*n + j] = -1;
                }
            }
        }

        for(int i = 0; i < m *n ; i ++){
            if(i == parent[i]){
                ans ++;
            }
        }

        return ans;

    }
};

int main(){
    Solution sc;
    vector<vector<char>> grids = { {'1','1'}};
    cout << sc.numIslands(grids);
}