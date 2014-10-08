/* There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

class Solution {

public:

	double findMedianSortedArrays(int A[], int m, int B[], int n) {

	int len = m+n;
	if(len<2){
		if((m==0)&&(n==0))
		  return 0;
		else if((m==1) && (n==0))
		  return A[0];
		else
		  return B[0];
	}

	int front, rear=0;
	int indexA=0;
	int indexB=0;


	while(indexA+indexB <= (m+n)/2){
        front = rear;
        if(indexA==m)   // A[] has no element left.
        {
            rear = B[indexB];
            indexB++;
        }
        else if(indexB==n) // B[] has no element left.
        {
            rear = A[indexA];
            indexA++;
        }
        else if (A[indexA]<B[indexB]) // A[] and B[] has elements, but A<B.
        {
            rear = A[indexA];
            indexA++;
        }
        else    // A>B
        {
            rear = B[indexB];
            indexB++;
        }
            
	}
    
    if(len%2==0) // the num of A+B is even
        return (front + rear)/2.0;
    else
        return rear;

	}


};


