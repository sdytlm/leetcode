/* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 * click to show more practice.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 *
 */

class Solution {

public:
	    int maxSubArray(int A[], int n) {
			if(n==1)
			  return A[0];
			int *Max = new int[n];
			int i;
			int result = -pow(2,30);
			Max[0] = A[0];
			for(i=1;i<n;i++) {							// 递推公式: f[i] = max(f[i-1]+A[i], A[i])
				Max[i] = max(Max[i-1]+A[i], A[i]);
			}
			for(i=0;i<n;i++) {                          // 找f[i]里最大的
				result = result>Max[i]?result:Max[i];
			}
			return result;



	    }

};
