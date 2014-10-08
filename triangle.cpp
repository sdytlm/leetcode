/* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *    [4,1,8,3]
 * ]
 *  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 */

// 从下往上扫描, 递推公式: f(x,y) = min(f(x+1,y+1), f(x+1,y))+ triangle[x][y]

class Solution {

public:
	    int minimumTotal(vector<vector<int> > &triangle) {
		    
			int result = 0;
			int i;
			int lastLine = triangle.size()-1;
			int **MIN = new int*[triangle.size()];         // MIN[i][j] 记录每个点从底到顶的最短路
			MIN[lastLine] = new int[triangle[lastLine].size()];
			for(i=0;i<triangle[lastLine].size();i++)
			  MIN[lastLine][i] = triangle[lastLine][i];

			for(i=triangle.size()-2;i>=0;i--){
				int j;
				MIN[i] = new int[triangle[i].size()];
				for(j=0;j<triangle[i].size();j++) {
					MIN[i][j] = min(MIN[i+1][j+1],MIN[i+1][j]) + triangle[i][j];  // 公式
				}
				
			}

			return MIN[0][0];


		}

};
