//
// Created by sjhuang on 2022/5/7.
//

#include "leetcode.h"

class Solution {
public:
    bool match(string a, string b){
        // 'A'、'C'、'G' 和 'T'
        if(a.size() != b.size()) return false;
        int count = 0;
        int n = a.size();
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]) count ++;
        }
        return count == 1;
    }

    // bfs 操作
    int minMutation(string start, string end, vector<string>& bank) {
        queue<int> q;
        set<string> vis;
        q.push(-1);
        vis.insert(start);
        int n = bank.size();
        int sz = 0, level = 0;
        while(!q.empty()){
            sz = q.size();
            for(int i = 0; i < sz; i++){
                int idx = q.front();
                q.pop();
                string key = (idx == -1)? start: bank[idx];
                cout << "key:" << key << endl;
                for(int j = 0; j < n; j++){
                    if(j != idx && match(key, bank[j]) && vis.count(bank[j]) == 0){
                        vis.insert(bank[j]);
                        cout <<key << ":" << bank[j] << " ";
                        if(bank[j] == end){
                            return level + 1;
                        }else{
                            q.push(j);
                        }
                    }
                }
                cout << endl;
            }
            level ++;
        }
        return -1;
    }
};


int main(){
    string  start = "AACCGGTT", end = "AAACGGTA";
    vector<string> bank = {"AACCGATT","AACCGATA","AAACGATA","AAACGGTA"};
    Solution sc;
    cout << sc.minMutation(start, end, bank) << endl;
    return 0;
}