//
// Created by sjhuang on 2022/4/7.
//

#include "leetcode.h"

class Solution {
public:
    bool rotateString(string s, string goal) {
        string ss = s + s;
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i = 0; i < 2*n; i++){
            bool match = true;
            for(int j = 0; j < n; j++){
                if(ss[i+j] != goal[j]){
                    match = false;
                    break;
                }
            }
            if(match) return true;
        }
        return false;
    }
};
int main(){
    Solution sc;
    sc.rotateString();
    return 0;
}