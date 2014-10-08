/*
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */

class Solution {

public:
        int result=0;
     int totalNQueens(int n) {
   if(n==0 || n==1)
     return n;
   int *status = new int[n];  // 记录第i行的queue在第几列
   int i;
   for(i=0;i<n;i++) {
    status[i] = -1;  // 初始化
   }
 

   dfs(status, 0,n);

   return result;          
     }

  void  dfs(int *status, int len, int n) {
   if(len == n) {
    result++;
    return;
   }
   int i;
   for(i=0;i<n;i++) {
    if(valid(status,len, i,n)){
     status[len] = i;
     dfs(status,len+1,n);
     status[len] = -1; // recursive

    }
   }
   return ;
  
  }

  bool valid(int *status, int len, int col, int n) {
   int j;
   for(j=0;j<len;j++) {  // check col and diagonal 
    if(status[j] == col || abs(j-len) == abs(col-status[j]))
      return false;
   }
   return true;
  }



};

