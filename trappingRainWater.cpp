/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6
*/


class Solution {
public:
    int trap(int A[], int n) {
        if(n<2)
            return 0;
        // Find the highest point.
        int i=0;
        int result = 0;
        int maxIndex = 0;
        for(i=0;i<n;i++)
            if(A[i]>A[maxIndex])
                maxIndex = i;
        // After find the peak, we will operate the left and right part separatelly.
        // left part: from left to right. for each bar, water = current peak of left - current bar.
        int leftPeak = 0;
        for(i=0;i<maxIndex;i++) {
            if(A[i]>leftPeak)
                leftPeak = A[i];
            else
                result += leftPeak - A[i];
        }
        
        // Right Part: from right to left. For each bar, water = current peak of right - current bar.
        int rightPeak = 0;
        for(i=n-1;i>maxIndex;i--) {
            if(A[i] > rightPeak)
                rightPeak = A[i];
            else
                result += rightPeak - A[i];
        }
        return result;
    }
};

