//
// Created by sjhuang on 2022/3/27.
//
#include <vector>
#include <iostream>
#include <string>
using  namespace std;
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        // n, n - 1
        vector<long long> ans;
        // 先找到所有的，再去查找，采用 10^15，暴力子
        int k = (intLength + 1)/2;
        // int count = 9*10^(k-1)
        int prev = 1;
        vector<long long> counts(k,10);
        for(int i = 0; i < k ; i++){
            if(i == k - 1)  counts[i] = 9*prev;
            else counts[i] = 10*prev;
            prev = counts[i];
        }
        for(int query: queries){
            if(query > counts[k-1]){
                ans.push_back(-1);
            }else{
                vector<int> cur(intLength,0);
                int idx = 0;
                while(query > 0){
                    int t = query%10;
                    if(intLength%2 != 0){
                        cur[k-1-idx] = cur[k-1+idx] = t;
                    }else {
                        cur[k-1-idx] = cur[k+idx] = t;
                    }
                    query /= 10;
                    idx ++;
                }
                cur[0] = cur[intLength-1] = cur[0] + 1;
                long long val = 0;
                for(int i = 0; i < intLength; i++){
                    val = val * 10 + cur[i];
                }
                ans.push_back(val);
            }
        }

        return ans;
    }
};

int main(){
    Solution sc;
    vector<int> quries = {1,2,3,4,5,89,90};
    sc.kthPalindrome(quries,3);
    return 0;
}
