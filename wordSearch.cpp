/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/

class Solution {
public:
  bool exist(vector<vector<char> > &board, string word) {
    if(word.empty())
        return true;
    if(board.empty())
        return false;
    int row = board.size();
    int col = board[0].size();
    int i,j;

    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if(board[i][j]==word[0]) {
                if(dfs(board, word, i,j,0))
                    return true;
            }
        }
    }
    return false;
  }

  bool dfs(vector<vector<char> > &board, string word, int row, int col, int index) {
      if(board[row][col]=='\0')
          return false;
      if(board[row][col]!=word[index])  // not match this char
          return false;
      else { // This char match
          if(index == word.size()-1)
              return true;
          char tmp = board[row][col];
          board[row][col] = '\0';
          // check 上一行
          if(row-1>=0 && dfs(board,word,row-1,col,index+1))
              return true;
          // check 下一行
          if(row+1<board.size() && dfs(board,word,row+1,col,index+1))
              return true;
          // check 左边列
          if(col-1>=0 && dfs(board,word,row,col-1,index+1))
              return true;
          // check 右边列
          if(col+1<board[0].size() && dfs(board,word,row,col+1,index+1))
              return true;
          board[row][col] = tmp;
          return false;
        }
  }

};
