//
// Created by sjhuang on 2022/4/6.
//

#include "leetcode.h"
class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // o(n)
        // 拓扑排序
        vector<int> ans;
        vector<int> d(n,0);

        // 1。 构建图的邻接矩阵
        vector<vector<int>> graph(n, vector<int>());
        for(vector<int> edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            d[edge[0]]++;
            d[edge[1]]++;
        }
        queue<int> q;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(d[i] == 1){
                q.push(i);
                d[i] = -1;
                count ++;
            }
        }
        int sz = 0;

        while (!q.empty()){
            sz = q.size();
            if(n- count <= 2){
                break;
            }
            for(int i = 0; i < sz; i++) {
                int p = q.front();
                q.pop();
                for (int node : graph[p]) {
                    d[node]--;
                    if (d[node] == 1) {
                        count ++;
                        q.push(node);
                        d[node] = -1;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(d[i] >= 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
int main(){
    Solution sc;
    int n = 6;
    vector<vector<int>> edges = {{1,0},{0,2},{0,3}, {3,4},{4,5}};
    vector<int> ans = sc.findMinHeightTrees(n, edges);
    return 0;
}