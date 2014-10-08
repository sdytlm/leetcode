/* Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Write a function to determine if a given target is in the array.
 */


#include <iostream>
using namespace std;

class Solution {

	public:

	 bool search(int A[], int n, int target) {
		 if(n==0)
		   return false;
		 int left=0;
		 int right=n-1;
		 while(left<right)
		 {
			cout << "haha" << endl;
			 int mid = (left+right)/2;
			 if(A[mid]==target)
			   return mid;
			 if(A[left]<=A[mid]) // left is ordered
			 {
				if((target<A[mid]) && (target>A[left]))
				{
					right=mid-1;
				}
				else
				    left=mid+1;
			 }
			 else // right is order
			 {
				 if((target>A[mid]) && (target<A[right]))
				 {
					 left=mid+1;
				 }
				 else
				    right=mid-1;

			 }
		 }
		 return false;
					        

	}

};

int main()
{
	Solution sol;
	int A[] = {1};
	int n=1;
	int res = sol.search(A,n,0);
	cout << res << endl;
	return 0;
}
