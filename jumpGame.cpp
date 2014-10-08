/* Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 *
 */

class Solution {

public:
	    bool canJump(int A[], int n) {
			if(n==0)
			  return false;
			int i;
			int *jumps = new int[n];	// max jumps left
			jumps[0] = 0;
			for(i=1;i<n;i++) {
				jumps[i] = max(jumps[i-1], A[i-1])-1;
				if(jumps[i] < 0)
				  return false;			
			}
	
			return jumps[n-1] >=0;
	        

		}

};
