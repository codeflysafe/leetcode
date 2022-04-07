//
// Created by sjhuang on 2022/3/19.
//
#include "leetcode.h"

using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis;
        for(string dd: deadends){
            vis.insert(dd);
        }
        string start = "0000";
        if(start == target) return 0;
        if(vis.count(start)) return -1;
        queue<string> q;
        q.push(start);
        vis.insert(start);
        int sz = 0, len = 0;
        while(!q.empty()){
            sz = q.size();
            for(int i =0; i < sz; i++){
                string item = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    for(int k = -1; k <= 1; k++){
                        if(k == 0) continue;
                        string tmp = item;
                        char c = (char)((((item[j] - '0') + 10 + k)%10) + '0');
                        if(!(c >= '0' && c <= '9')){
                            continue;
                        }
                        tmp[j] = c;
                        // cout << i << " " << j << " " << k << " " << tmp << endl;
                        if(tmp == target){
                            return len + 1;
                        }else if(vis.count(tmp)) {
                            continue;
                        }else{
                            q.push(tmp);
                            vis.insert(tmp);
                        }
                    }
                }
            }
            len ++;
        }
        return -1;
    }
};


int main(){
    vector<string> dd = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target = "8888";
    Solution sc;
    cout << sc.openLock(dd, target) ;
    return 0;
}