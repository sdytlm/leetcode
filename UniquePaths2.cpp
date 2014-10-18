/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
          if(obstacleGrid.empty()) {
              return 0;
          }

          int row = obstacleGrid.size();
          int col = obstacleGrid[0].size();

          int **dp = new int*[row+1];

          int i,j;

          for(i=0;i<=row;i++) {
              dp[i] = new int[col+1];
              memset(dp[i],0,sizeof(int)*(col+1));
          }

          for(i=1;i<=row;i++) {
            for(j=1;j<=col;j++) {
              if(obstacleGrid[i-1][j-1]==1) // grid[i][j] is an onstacle
                dp[i][j] = 0;
              else {   // grid[i][j] is not an obstacle
                    if(i==1 && j==1) {
                        dp[i][j] = 1;
                        continue;
                    }
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];  // dp[i][j]表示到grid[i][j]的unique path数量.
                }
            }
          }

          return dp[row][col];


    }
};
