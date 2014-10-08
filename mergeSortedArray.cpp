/* Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 *
 */


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int indexA=m-1;      // point to the highest value of A
			int indexB=n-1;      // point to the highest value of B
			int i = m+n-1;       // unorganized position in A.
			
			while(indexA>=0 && indexB>=0) {
				A[i--] = A[indexA]>=B[indexB]?A[indexA--]:B[indexB--];       
			}

			while(indexB>=0) {
				A[i--] = B[indexB--];
			}
			return ;
    }
};
