/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
       int m = grid.size();
	   if(m==0)
		 return 0;
	   int n = grid[0].size();
	   // Initialize dp
	   int **dp = new int*[m+1];
	   int i,j;
	   for(i=0;i<=m;i++)
		 dp[i] = new int[n+1];
	  
	   for(i=0;i<=m;i++)
		 dp[i][0] = pow(2,30);

	   for(i=0;i<=n;i++)
		 dp[0][i] = pow(2,30);

	   dp[1][1] = grid[0][0];
	   //dp
	   
	   for(i=1;i<=m;i++) {
		   for(j=1;j<=n;j++) {
				if(i==1 && j==1)
				  continue;
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
		   
		   }
	   }
	   return dp[m][n];

    }
};
