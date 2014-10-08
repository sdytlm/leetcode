/* Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 *
 *
 */

class Solution {

public:
	    int jump(int A[], int n) {
			if(n<2)
			  return 0;
			int step = 0;	// minimal steps
			// 当前决策能覆盖的区域
			int left = 0;	
			int right = 0;
			
			while(left<=right) {
				step++;
				int oldRight = right;      
				int i;
				for(i=left;i<=oldRight;i++) {           // 搜索left 到 right这个区间里能找到的最大距离。
					int newRight = i+A[i];
					if(newRight>=n-1)	return step;	// reach last index
					if(newRight>right) right=newRight;  // Find a better solution
				}
				left = oldRight+1;


			}
			return 0; 

		}

};
