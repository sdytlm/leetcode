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
        int low = matrix.size();
        int col = matrix[0].size();
        int roundNum = (min(low,col)+1)/2;  // 跑几轮
        int i;
        for(i=0;i<roundNum;i++) {
          int j;
          if(low-roundNum-1==roundNum) { // 只有一行.

          }
          // Print from left to right
          for(j=i;j<col-roundNum;j++)


        }

    }
};
