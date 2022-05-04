//
// Created by sjhuang on 2022/4/17.
//

#include "leetcode.h"

class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k) return s;
        string res = "";
        int cur = 0;
        for(int i = 0; i < s.size(); i += k){
            cur = 0;
            for(int j = 0; j < k && i + j < s.size(); j++){
                cur = cur  + (s[i+j] - '0');
            }
            res += to_string(cur);
        }
//        cout << res << endl;
        if(res.size() > k){
            res = digitSum(res,k);
        }
        return res;
    }
};

int main(){
    Solution sc;
    string str = "11111222223";
    int k= 3;
    str = sc.digitSum(str,k);
    cout <<str<< endl;
    return 0;
}