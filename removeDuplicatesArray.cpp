/* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 For example,
 Given input array A = [1,1,2],
 
 Your function should return length = 2, and A is now [1,2].
 */
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int length = n;
        if((n==0) || (n==1)) // only 0/1 element in the array.
            return n;
        int val = A[0];
        int i=0,j=1;
        int maxInt = pow(2,31);
        while ((j<length))// If found equal element, otherwise, test next element.
        {
            while((j<length) && (A[j] == val)) // Find the next different
            {
                A[j] = maxInt;
                j++;
            }
            i=j;
            val = A[i];
            j++;
            
        }
        int len=n;
        i=1,j=1;
        while(j<length)
        {
            while((j<length) && (A[j]==maxInt))
            {
                j++;
                len--;
            }
            A[i] = A[j];
            i++;
            j++;
        }
        return len;
    }
};


// A better solution

class Solution{
public:
    int removeDuplicates(int A[], int n){
    if(n==0)
    {
        return 0;
    }
    int i=1;
    int index = 0;
    while(i<n)
    {
        if(A[i]!=A[index])
            A[++index] = A[i];
        i++;
    }
        return index+1;
    }
};