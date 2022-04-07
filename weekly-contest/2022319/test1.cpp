//
// Created by sjhuang on 2022/3/19.
//

#include "leetcode.h"

using namespace  std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size(), n = typed.size();
        if(n < m) return false;
        int i = 0, j = 0;
        while(i < m && j < n){
//            cout << i << " " << j << endl;
            if(name[i] != typed[j]){
                return false;
            }else{
                // 两者相同, 统计数量
                int n1 = i + 1, t1 = j + 1;
                while(n1 < m && name[i] == name[n1]){
                    n1 ++;
                }
                while(t1 < n && typed[j] == typed[t1]){
                    t1 ++;
                }
                if(t1 - j < n1 - i) return false;
                i = n1;
                j = t1;
            }
        }
        return i == m && j == n;
    }
};

int main(){
    vector<int> ts = {1,2,3};
    Solution sc;
    string name = "saeed", typed = "ssaaedd";
    cout << sc.isLongPressedName(name, typed);
    return 0;
}