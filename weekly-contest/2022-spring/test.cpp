//
// Created by sjhuang on 2022/4/16.
//

#include "leetcode.h"
int main(){
    map<vector<int>, int> s;
    s[{1,2}] =1;
    s[{3,4}] =1;
    auto it = s.lower_bound({1,4});
    if(it != s.begin()){
        it--;
    }
    cout << it->first[0] << endl;
    return 0;
}