//
// Created by sjhuang on 2022/4/4.
//
#include "leetcode.h"


// 307. 区域和检索 - 数组可修改
// 线段树
//
// Created by sjhuang on 2022/4/4.
//


// 307. 区域和检索 - 数组可修改
// 线段树
class NumArray {
public:
    vector<int> sums;
    int n;

    void add(int left, int right,int index, int idx, int val){
        if(left > right) return;
        if(left == right) {
            sums[index] += val;
            return;
        }
        int mid = left + ((right - left) >> 1);
        if(mid > idx){
            add(mid + 1, right, index * 2 + 2, idx, val);
        }else{
            add(left , mid, index * 2 + 1, idx, val);
        }
        // 后更新
        sums[index] = sums[index*2 + 1] + sums[index*2 + 2];
    }

    int range(int left, int right, int index, int l, int r){
        if(left > right) return 0;
        if(left == right) return sums[index];
        int mid = left + ((right - left) >> 1);
        int sum = 0;
        if(r > mid){
            sum += range(mid+1, right, index * 2 + 2, mid+1, r);
        }
        if(l <= mid){
            sum += range(left, mid, index * 2 + 1, l, mid);
        }
        return sum;
    }



    NumArray(vector<int>& nums) {
        n = nums.size();
        sums.resize(4*n,0);
        for(int i = 0; i < n; i++){
            add(0, n-1,0 ,i, nums[i]);
        }
    }

    void update(int index, int val) {
        add(0, n-1,0 ,index,val);
    }

    int sumRange(int left, int right) {
        return range(0, n-1, 0, left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){
    vector<int> nums = {1,3,5};
    NumArray* obj = new NumArray(nums);
    obj->update(1,2);
    int param_2 = obj->sumRange(0,2);
    cout << param_2 << endl;
    return 0;
}