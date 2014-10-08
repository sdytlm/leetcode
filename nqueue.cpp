/* The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],
 
 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
 ]
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;




class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        
        vector<vector<string> >result;
        vector<string> oneSolution;
        int *status = new int[n];     // 记录当前棋盘的状态,第i行皇后所在的列
        int i;
        for(i=0;i<n;i++) {
            status[i] = -1;
        }
        dfs(result,status, 0,n);
        return result;
    }
    
    void dfs(vector<vector<string> > &result, int *status, int lineIndex, int n) {
        if(lineIndex == n) {        // Find one solution
            vector<string> oneSolution(n,string(n,'.'));
            int j;
            for(j=0;j<n;j++)                     // 把status矩阵&#65292;转化成一个解
                oneSolution[j][status[j]] = 'Q';
            result.push_back(oneSolution);
            return ;
        }
        int i;
        for(i=0;i<n;i++) { // Find a valid position in line lineIndex
            if(isValid(status,lineIndex,i)) {
                status[lineIndex] = i;      // update status matrix
                dfs(result,status,lineIndex+1,n);  // Find another line.
                status[lineIndex] = -1;
            }
            
        }
        return ;
        
    }
    
    
    bool isValid(int *status, int row, int col)
    {
        for(int i = 0; i < row; i++)//只需要判断row前面的行&#65292;因为后面的行还没有放置
            if(status[i] == col || abs(row - i) == abs(col - status[i]))
                return false;
        return true;
    }
    
    
};


