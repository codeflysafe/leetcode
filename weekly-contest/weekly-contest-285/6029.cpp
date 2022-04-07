//
// Created by sjhuang on 2022/3/20.
//
#include <queue>
#include <vector>
#include <map>

using namespace  std;
class Solution {
public:

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {

        vector<int> ans(12, 0);
        multimap<double, int, less<double>> pairs;
        for(int i = 0; i <= 11; i++){
//            pairs[(i*1.0/(aliceArrows[i] + 1))] = i;
            pairs.insert(std::make_pair((i*1.0/(aliceArrows[i] + 1)), i));
        }

        int cur = 0;
        for(auto pair : pairs){
            if(cur + pair.second <= numArrows){
                cur += pair.second;
                ans[pair.second] = aliceArrows[pair.second] + 1;
            }

            if(cur == numArrows) break;
        }
        return ans;
    }
};