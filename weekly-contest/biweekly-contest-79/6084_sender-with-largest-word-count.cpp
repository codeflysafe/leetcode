//
// Created by sjhuang on 2022/5/28.
//
#include "leetcode.h"

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> counts;
        int n = messages.size();
        for(int i = 0; i < n; i++){
            string sender = senders[i];
            string message = messages[i];
            int count = 1;
            for(char c: message){
                if(c == ' '){
                    count ++;
                }
            }
            counts[sender] += count;
        }

        string res = "";
        int cur = 0;
        for(auto p: counts){
            if(p.second > cur){
                res = p.first;
                cur = p.second;
            }else if(p.second == cur){
                if(res < p.first){
                    res = p.first;
                }
            }
        }
        return res;
    }
};

