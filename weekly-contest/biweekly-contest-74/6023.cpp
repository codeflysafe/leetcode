//
// Created by sjhuang on 2022/3/19.
//
#include <vector>
#include <string>
#include <queue>
#include <map>
using  namespace  std;



class Solution {
public:

    static int cmp(vector<int> p1, vector<int> p2){
        if(p1[1] != p2[1]){
            return p1[1] > p2[1];
        }
        return p1[0] < p2[0];
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {

        int n = floor.size();
        int ans = 0;
        priority_queue<vector<int>, cmp> p;
        int i = 0, j = 0, cur = 0;
        for(; j < carpetLen; j++){
            if(floor[j] == '1'){
                cur ++;
                ans++;
            }
        }
        // 构建数组 {i, len}
        for(; i < n; i++){
            if(floor[i] == '1'){
                p.push({i, cur});
                cur --;
            }
            if(j < n && floor[j] == '1'){
                cur ++;
                ans++;
            }
        }
        i = 0;
        while(!p.empty() && i < numCarpets){
            vector<int> item = p.top();
            p.pop();
            i++;
            if(item[1] <= carpetLen){
                // 刚好消除掉， 同时将出发点在 item[0] - item[0] + carpetLen 之间的全部消除掉
                ans -= item[1];
            }else if(item[1] > carpetLen){
                ans -= carpetLen;
                p.push({i + carpetLen, item[1] - carpetLen});
            }
        }


    }
};