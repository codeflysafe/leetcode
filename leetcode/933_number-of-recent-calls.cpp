//
// Created by sjhuang on 2022/5/6.
//
#include "leetcode.h"
class RecentCounter {
public:

    list<int> ts;

    RecentCounter() {
    }

    int ping(int t) {
        // 二分法，查找 t-3000 和 t
        ts.push_back(t);
        while(!ts.empty() && ts.front() < t-3000){
            ts.pop_front();
        }
        return ts.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main(){
    RecentCounter* obj = new RecentCounter();
    int t = 120;
    cout << obj->ping(t) << endl;
    return 0;
}

