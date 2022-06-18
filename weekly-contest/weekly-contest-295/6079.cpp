//
// Created by sjhuang on 2022/5/29.
//
#include "leetcode.h"

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        setprecision(2);
        string res = "";
        int n = sentence.size();
        string ky = "";
        for(int i = 0; i < n; i++){
            if(sentence[i] == ' ' || i == n - 1){
                if(i == n-1 && sentence[i] != ' ') ky += sentence[i];
                // ky 是一个单词，对他进行判断
                if(ky[0] == '$'){
                    int num = 0;
                    int k  = ky.size();
                    bool isnum = true;
                    for(int j = 1; j < k; j++){
                        if(ky[j] >= '0' && ky[j] <= '9'){
                            num = num*10 + (ky[j] - '0');
                        }else{
                            isnum = false;
                            break;
                        }
                    }
                    if(isnum){
                        // return to_string(num);
                        float re = int(num*discount)*0.01;
                        char buf[12];
                        sprintf(buf,"%2.f",re);
                        return to_string(buf);
                        if(res.size() == 0) res += "$" + to_string(buf);
                        else res += " $" + to_string(re);
                    }else{
                        if(res.size() == 0) res = ky;
                        else res += " " + ky;
                    }
                }else{
                    if(res.size() == 0) res += ky;
                    else res += " " + ky;
                }

                ky = "";
            }else{
                ky += sentence[i];
            }
        }
        return res;
    }
};

