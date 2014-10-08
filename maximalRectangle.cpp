/* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 
 *
 */

class Solution {

public:
	    int maximalRectangle(vector<vector<char> > &matrix) {
			if(matrix.size()==0)
			    return 0;
			    
			int row = matrix.size();
			int col = matrix[0].size();
			int **dp = new int *[row];   // 记录每行所形成的最长连续矩阵
			int i,j,k;
			int result = -pow(2,30);
			
			
			
			for(i=0;i<row;i++) {
				dp[i] = new int [col];
			}

			// 初始化dp[i][len-1]
			for(i=0;i<row;i++) {
				if(matrix[i][col-1] == '1')
				  dp[i][col-1] = 1;
				else 
				  dp[i][col-1] = 0;
			}

			// 从右往左，从下往上, 用dp检查每个行，最长连续矩阵
			for(i=row-1;i>=0;i--) {
				for(j=col-2;j>=0;j--) {
					dp[i][j] = matrix[i][j]=='1'?dp[i][j+1]+1:0;
				}
			}

			// 知道每行的最大width，计算面积

			
			for(i=0;i<row;i++) {
				for(j=0;j<col;j++) {
				int width = dp[i][j];
				int minWidth = pow(2,30);
				// 计算以(i,j)为左上角点的所有矩形的面积
					for(k=i;k<row;k++) {
						 minWidth = min(minWidth,dp[k][j]);
						 int area = minWidth * (k-i+1);
						 result = max(result,area);

					}

				}
			}

			return result;

	    }

};
