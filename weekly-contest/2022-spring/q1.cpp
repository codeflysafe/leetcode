//
// Created by sjhuang on 2022/4/16.
//
#include <vector>
#include <cmath>
class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {

        // operations[j] = [x, y] 表示在第 j 次的赠送中 第 x 位勇者将自己一半的宝石（按需向下取整）赠送给第 y 位勇者。
        for(vector<int> op: operations){
            int x = op[0], y = op[1];
            int t = gem[x];
            gem[x] -= t/2;
            gem[y] += t/2;
        }

        int less = gem[0], more = gem[0];
        // 请找到拥有最多宝石的勇者和拥有最少宝石的勇者，并返回他们二者的宝石数量之差。
        for(int g: gem){
            less = min(less, g);
            more = max(more, g);
        }

        return more - less;
    }
};