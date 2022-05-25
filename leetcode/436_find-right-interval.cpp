/*
 * @Author: sjhuang
 * @Date: 2022-05-20 20:14:48
 * @LastEditTime: 2022-05-20 20:54:16
 * @FilePath: /leetcode/leetcode/436_find-right-interval.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        map<int,int> indexes;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            indexes[intervals[i][0]] = i;
        }
        vector<int> ans;
        for(int i = 0; i < n; i ++){
            int end = intervals[i][1];
            auto p = indexes.lower_bound(end);
            if(p != indexes.end()){
                if(p->second == i){
                    p++;
                    if(p!= indexes.end()){
                        ans.push_back(p->second);
                    }else{
                        ans.push_back(-1);
                    }
                    
                }else{
                    ans.push_back(i);
                }
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}