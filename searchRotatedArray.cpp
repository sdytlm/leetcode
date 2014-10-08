/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.   
 */


class Solution {
	public:
		    int search(int A[], int n, int target) {
				int left = 0;
				int right = n-1;
				while(left<=right)
				{
					int mid = (left+right)/2;
					if(target > A[mid])    // Case1: target > A[mid] But we may search the front part of array.
					{
						if((A[left]>A[right]) && (target>A[right]) && (A[mid]<A[right]))
						{
							right = mid-1;
						}
						else // Normal situation for the binary search
						{
							left = mid+1;
						}

					}
					else if(target < A[mid]) // Case2: target < A[mid], But we may search the rear part of array.
					{
						if((A[left]>A[right]) && (target<=A[right]) && (A[mid]>A[right]))
						{
							left = mid+1;
						}
						else // Normal situation for the binary search.
						  right = mid-1;

					}
					else // case3: target == A[mid]
					{
                         return mid;
					}
				}
				return -1;

			}
};
