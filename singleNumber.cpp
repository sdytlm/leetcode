/*Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

class Solution {
public:
int singleNumber(int A[], int n) 
{
// Note: The Solution object is instantiated only once and is reused by each test case.
         if (n==1)
         {
    		 return A[0];
		 }
         for (int i=0; i<n-1; i++)
              A[i+1] ^= A[i];
         return A[n-1];
}
};
