//
// Created by sjhuang on 2022/5/28.
//
#include "leetcode.h"

class BookMyShow {
public:

    int n, m;
    int usen = 0;
    int usem = 0;
    vector<int> sites;
    // 空闲容量
//    vector<long long> caps;
    vector<long long> tries;

    void add(int left, int right, int index, int idx, long long incr){
        if(left == right){
            tries[index] += incr;
            return;
        }
        int mid = left + ((right - left) >> 1);
        if(idx <= mid){
            add(left, mid, index * 2 + 1, idx, incr);
        }else{
            add(mid + 1, right, index * 2 + 2, idx, incr);
        }
        tries[index] = tries[index * 2 + 1] + tries[index * 2 + 2];
    }
    long long range(int left, int right, int index,int l, int r){
        if(left >= l && right <= r) return tries[index];
        else{
            int mid = left + ((right - left) >> 1);
            long long ans = 0;
            if(l <= mid){
                ans += range(left, mid, index * 2 + 1, l , r);
            }
            if(r > mid){
                ans += range(mid + 1, right, index * 2 + 2, l , r);
            }
            return ans;
        }
    }

    BookMyShow(int n, int m) {
        this->n = n, this->m = m;
        sites.resize(n,0);
        tries.resize(4*n + 2, 0);
        for(int i = 0; i < n; i++){
            add(0, n-1, 0, i, m);
        }
    }

    vector<int> gather(int k, int maxRow) {
        if(k > m) return {};
        if(usen <= maxRow){
            if(sites[usen] <= m - k){
                sites[usen] += k;
                add( 0, n-1, 0, usen, -k);
                return {usen, sites[usen] - k};
            }else{
                //
                usen + 1;
                if(usen <= maxRow){
                    add( 0, n-1, 0, usen, -k);
                    sites[usen] = k;
                    return {usen, 0};
                }else return {};
            }
        }else return {};
    }

    bool scatter(int k, int maxRow) {
        if(range(0, n-1, 0, 0, maxRow) < k) return false;
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
