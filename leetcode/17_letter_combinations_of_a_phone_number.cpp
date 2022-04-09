//
// Created by sjhuang on 2022/4/7.
//
#include "leetcode.h"

class Solution {
public:
    vector<string> ans;

    void dfs(vector<vector<char>> &tables, string digits, string cur, int i, int n){
        if(i >= n) {
            ans.push_back(cur);
            return;
        }

        // 当前的数字
        int digit = digits[i] - '0' - 1;
        string tmp = cur;
        for(char c: tables[digit]){
            // 符合条件的
            cur = cur + c;
            dfs(tables, digits, cur, i + 1, n);
            cur = tmp;
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return {};
        // build tables
        vector<vector<char>>  tables= {{}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'},
                                       {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};

        dfs(tables, digits,"", 0,  n);
        return ans;
    }
};

int main(){
    string digits = "23";
    Solution sc;
    vector<string> ans = sc.letterCombinations(digits);
    for(string item: ans){
        cout << item << endl;
    }
    return 0;
}