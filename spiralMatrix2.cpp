/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > result;
    vector<int> tmp;
    if(n==0)
      return result;
    if(n==1) {
      tmp.push_back(1);
      result.push_back(tmp);
      return result;
    }
    int i,j,k,index=1;
    // 初始化result
    for(i=0;i<n;i++) {
      tmp.clear();
      for(j=0;j<n;j++) {
        tmp.push_back(0);
      }
      result.push_back(tmp);
    }

    // 画蛇行
    for(k=0;k<n/2;k++) {
      i=k;
      j=k;
      // 行(左→右)
      while(j<n-k-1){
        result[i][j++] = index++;
      }
      // 列(上→下)
      while(i<n-k-1){
        result[i++][j] = index++;
      }

      // 行(右→左)
      while(j>k) {
        result[i][j--] = index++;
      }

      // 列(下→上)
      while(i>k) {
        result[i--][j] = index++;
      }
    }
    // 若n为奇数则少了一个点
    if(n%2==1) {
      result[n/2][n/2] = index++;
    }
    return result;
  }
};
