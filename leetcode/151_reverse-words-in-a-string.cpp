//
// Created by sjhuang on 2022/5/5.
//

#include "leetcode.h"

class Solution {
public:
    string reverseWords(string s) {
        string ans, keyword;
        int prev = 0, n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(i - prev > 0){
                    keyword = s.substr(prev, i - prev);
                    if(ans.size() == 0){
                        ans = keyword;
                    }else{
                        ans = keyword + " "  + ans;
                    }
                }
                prev = i + 1;
            }
        }
        if(n - prev > 0){
            keyword = s.substr(prev, n - prev);
            if(ans.size() == 0){
                ans = keyword;
            }else{
                ans = keyword + " "  + ans;
            }
        }

        return ans;
    }
};


int main(){
    string str;
    getline(cin, str);
    Solution sc;
    cout << sc.reverseWords(str) << endl;
    return 0;
}