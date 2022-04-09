//
// Created by sjhuang on 2022/4/7.
//

#include "leetcode.h"

class Solution {
public:

    // 数字 1-9 在每一行只能出现一次。
    // 数字 1-9 在每一列只能出现一次。
    // 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
    bool isValid(vector<vector<char>> &board, int x, int y){
        // 判断填入某个数字是否合法
        //  数字 1-9 在每一行只能出现一次。
        for(int i = 0; i < 9; i++) {
            // 如果已经存在
            if(y != i && board[x][y] == board[x][i]) return false;
        }

        // 数字 1-9 在每一列只能出现一次。
        for(int i = 0; i < 9; i++){
            // 如果已经存在
            if(x != i && board[x][y] == board[i][y]) return false;
        }

        // 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
        int i = x/3, j = y/3;
        for(int k = 0; k < 3; k++){
            for(int m = 0; m < 3; m ++){
                if(3*i + k != x && 3*j + m != y && board[x][y] == board[3*i + k][3*j + m]) return false;
            }
        }
        return true;
    }

    bool backProp(vector<vector<char>>& board, int x, int y, int val){

        board[x][y] = char(val + '0');
        if(!isValid(board,x,y)) {
            board[x][y] = '.';
            return false;
        }
        bool ok = true;
        if(x + 1 < 9 && board[x+1][y] == '.'){
            // 下一步
            for(int i  =1; i <= 9; i++){
                if(backProp(board, x + 1, y, i)){
                    ok = true;
                    break;
                }
            }
        }

        if(y + 1 < 9){
            for(int i  =1; i <= 9; i++){
                if(backProp(board, x , y + 1, i)){
                    break;
                }
            }
        }

        return true;

    }

    void solveSudoku(vector<vector<char>>& board) {

    }
};

int main(){

    return 0;
}
