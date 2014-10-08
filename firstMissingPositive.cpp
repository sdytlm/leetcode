/* Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 */


class Solution {

public:
     int firstMissingPositive(int A[], int n) {
   if(n==0)
       return 1;
   int i;                                                       // A[i]记录i+1;
   for(i=0;i<n;i++) {                                           // 对于每一个A[i]&#65292; 如果不等于i+1,则和A[A[i]-1]换位置&#12290;
    if(A[i]!=i+1 && A[i] >=1 && A[i]!=A[A[i]-1] && A[i] < n) {
     swap(A[i], A[A[i]-1]);
     i--;
    }
   
   }
   i=0;
   while(i<n) {                                                // 遍历一边找A[i]不是i+1的
    if(A[i]!=i+1)
        break;
    else
        i++;
   }
   return i+1;
         
  }

};



