/* Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
		if(n<1) {
		  result.push_back(-1);
		  result.push_back(-1);
		  return result;
		}
		// Find lower bound
		int i=0;
		while(i<n) {
			if(A[i] == target)
			  break;
			else
			  i++;
		}
		if(i<n)
			result.push_back(i);
		else {
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		// Find upper bound
		i=n-1;
		while(i>=0) {
			if(A[i] == target)
			  break;
			else
			  i--;
		}
		if(i>=0)
		  result.push_back(i);
		return result;
	
    }
};
