//
// Created by sjhuang on 2022/4/17.
//

#include "leetcode.h"

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counts;
        for(int task: tasks){
            counts[task] ++;
        }
        int ans = 0;
        // 在每一轮中，你可以完成 2 个或者 3 个 相同难度级别 的任务。
        for(auto p: counts){
            if(p.second < 2){
                return -1;
            }else{
                if(p.second%3 == 1 || p.second%3 == 2){
                    ans += p.second/3 + 1;
                }else {
                    ans += p.second/3;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sc;
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    cout << sc.minimumRounds(tasks);
    return 0;
}