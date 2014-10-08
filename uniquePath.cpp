/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 */

class Solution {

public:

	    int uniquePaths(int m, int n) {
			
			int **array = new int*[m+1];
			int i;
			for(i=0;i<=m;i++)
			  array[i] = new int[n+1];
			for(i=0;i<=m;i++)
			  array[i][0] = 0;        // 第0行和第0列不用
			for(i=0;i<=n;i++)
			  array[0][i] = 0;

			int j;
			array[1][1] = 1;          // 起点设为1
			for(i=1;i<=m;i++) {
				for(j=1;j<=n;j++) {
				    if(i==1 && j==1)
				        continue;
					array[i][j] = array[i-1][j] + array[i][j-1];
				}
			
			}
			return array[m][n];


		}

};
