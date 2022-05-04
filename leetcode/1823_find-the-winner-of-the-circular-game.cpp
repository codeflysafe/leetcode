#include "leetcode.h"

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        for(int i = 0; i < n; i++){
            nums.push_back(i);
        }
        int num = n, start = 0;
        while(num > 1){
            start = (start + k - 1) % num;
            nums.erase(nums.begin() + start);
            num --;
        }
        return nums[0];
    }
};

int main(){
  Solution sc;
  cout << sc.findTheWinner(6,5) + 1;
  return 0;
}