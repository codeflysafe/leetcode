//
// Created by sjhuang on 2022/6/8.
//
#include "leetcode.h"

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // 在一条直线上
        if(points[0][0] == points[1][0] == points[2][0]) return false;
        if(points[0][1] == points[1][1] == points[2][1]) return false;
        int x1 = points[0][0], x2 = points[1][0], x3 = points[2][0];
        int y1 = points[0][1], y2 = points[1][1], y3 = points[2][1];
        cout << x1 << x2 << x3 << y1 << y2 << y3 << endl;
        cout << y3 * (x2 - x1) << endl;
        cout << (y2-y1)*x3 + y1*x2 - x1*y2 << endl;
        if(y3*(x2-x1) == (y2-y1)*x3 + y1*x2 - x1*y2) return false;
        return true;
    }
};

int main(){
    Solution sc;

    return 0;
}
