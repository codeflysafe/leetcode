//
// Created by sjhuang on 2022/4/7.
//

#include "leetcode.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < count; ++j) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main(){
    Solution sc;
    vector<string> prefixes = {"flower","flow","flight"};
    cout << sc.longestCommonPrefix(prefixes);
    return 0;
}