//
// Created by sjhuang on 2022/5/6.
//
#include "leetcode.h"
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> collects;
        for(string str: strs){
            string key = str;
            sort(key.begin(), key.end());
            collects[key].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto p: collects){
            ans.push_back(p.second);
        }
        return ans;
    }
};

int main(){
    Solution sc;
    vector<string> nns {"eat", "tea", "tan", "ate", "nat", "bat"};
    sc.groupAnagrams(nns);
    return 0;
}