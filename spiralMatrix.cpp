/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.size()==0)
          return result;
        int row = matrix.size();
        int col = matrix[0].size();
        int i;
        if(row == 1) {
          for(i=0;i<col;i++)
            result.push_back(matrix[0][i]);
          return result;
        }

        int roundNum = (min(row,col)+1)/2;  // 跑几轮

        for(i=0;i<roundNum;i++) {
          int j;
          if(row-i-1==i) { // 只有一行剩下.
              for(j=i;j<col-i-1;j++)
                result.push_back(matrix[i][j]);
              result.push_back(matrix[i][j]);
              return result;
          }

          if(col-i-1==i) { // 只有一列剩下
              for(j=i;j<row-i-1;j++)
                result.push_back(matrix[j][i]);
              result.push_back(matrix[j][i]);
              return result;
          }
          // Print from left to right
          for(j=i;j<col-i-1;j++) {
              result.push_back(matrix[i][j]);
          }

          // Print from top to down
          for(j=i;j<row-i-1;j++) {
              result.push_back(matrix[j][col-i-1]);
          }

          // Print from right to left
          for(j=col-i-1;j>i;j--) {
             result.push_back(matrix[row-i-1][j]);
          }
         // Print from down to top
          for(j=row-i-1;j>i;j--) {
             result.push_back(matrix[j][i]);
          }


        }

  return result;
    }
};
