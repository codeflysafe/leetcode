//
// Created by sjhuang on 2022/3/19.
//
#include <vector>
#include <iostream>
#include <queue>
using namespace  std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        // if(n == 1) return 1;
        // 优先队列
        priority_queue<float,vector<float>, less<float>> sortNums;
        float sum = 0;
        for(int num: nums){
            sortNums.push(num);
            sum += num;
        }
        // return sortNums.top();
        int ans = 0;
        float  cur = 0.0f;
        while(true){
            int num = sortNums.top();
            sortNums.pop();
            cur += num/2.0;
            ans ++;
            if(2*cur >= sum){
                if(2*cur == sum) return ans -1;
                else return ans;
            }else{
                sortNums.push(num/2.0);
            }
        }
        return n;
    }
};

int main(){
    // 312653
    // 312273
    Solution sc;
    vector<int> nums = {484,35,664,737,45,1,958,191,414,87,834,715,488,243,933,331,975,491,523,618,521,797,917,693,450,57,867,385,383,828,784,236,661,271,125,771,986,984,346,659,998,832,87,96,204,676,621,187,157,825,45,38,923,871,795,22,257,259,324,416,683,412,971,110,730,428,181,300,803,183,621,933,522,280,282,785,411,937,591,14,122,876,745,419,922,432,239,709,311,523,748,521,650,754,213,186,237,855,390,97,591,993,857,272,356,73,531,133,285,263,73,317,429,764,798,757,51,986,170,793,799,396,594,131,706,453,774,425,899,625,833,906,305,892,682,692,222,698,781,1000,792,664,811,155,680,418,659,29,471,501,801,351,150,162,456,829,351,485,39,833,175,353,185,26,720,926,296,921,53,297,949,740,194,299,202,326,896,320,440,366,736,423,93,460,879,262,215,60,709,332,766,43,614,191,83,948,39,578,904,329,605,84,927,926,639,25,413,79,904,368,197,999,25,309,418,756,669,271,771,993,226,586,851,527,918,557,38,200,797,876,481,298,578,200,283,929,480,160,146,174,986,177,94,156,701,918,278,389,41,842,316,875,371,301,935,36,122,335,504,700,48,309,164,522,588,265,679,859,391,696,437,722,132,619,69,50,462,402,91,367,370,775,242,763,945,221,575,456,907,804,657,754,44,364,457,380,951,844,234,978,801,843,230,343,262,622,30,757,143,471,470,121,49,67,816,982,132,121,923,396,96,278,778,198,826,846,891,839,871,949,567,680,557,300,478,963,1,674,85,379,841,416,953,504,971,615,732,318,194,733,847,131,338,971,603,653,160,821,103,241,493,865,78,391,855,977,698,450,113,631,342,134,844,786,825,24,391,140,600,437,470,62,516,695,402,225,463,623,134,422,445,375,783,677,235,111,277,368,399,511,814,249,308,476,205,524,752,831,240,72,758,700,788,749,878,541,467,808,504,426,58,622,839,966,251,576,460,723,740,514,585,418,376,266,439,602,19,185,878,586,45,536,720,688,467,203,140,734,227,219,59,40,591,915,58,823,458,404,210,665,303,893,653,703,918,529,705,85,367,611,619,715,39,526,961,832,131,553,233,593,193,255,111,745,522,836,795,928,742,157,410,353,741,610,663,767,331,368,491,3,824,478,258,247,917,464,54,473,919,977,150,876,326,233,296,940,421,545,999,804,291,845,151,486,413,763,728,518,2,571,54,135,170,348,208,733,12,951,666,921,37,86,898,892,395,938,36,175,179,958,770,767,49,133,14,655,213,589,803,502,258,517,139,153,752,737,723,355,581,83,63,455,524,286,699,440,543,820,450,295,356,703,550,949,881,141,164,722,348,340,489,538,386,98,777,111,654,837,281,270,507,803,32,3,335,80,869,887,505,924,417,884,499,950,99,269,706,766,659,684,801,930,298,865,824,258,137,83,670,279,21,883,100};
    cout << sc.halveArray(nums);
    return 0;
}