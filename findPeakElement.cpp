/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

*/

class Solution {
public:
  int findPeakElement(const vector<int> &num) {
      int left = 0;
      int right = num.size()-1;

      while(left<=right) {
          int mid = (left+right)/2;

          if(mid==0) {    // 第一个元素
              if(num[mid]>num[mid+1])
                  return mid;
              else
                  left = mid+1;
          }
          else if(mid==num.size()-1) {  // 最后一个元素
              if(num[mid]>num[mid-1])
                  return mid;
              else
                  right = mid-1;
          }

          else {  // 其他元素
              if(num[mid]>num[mid+1] && num[mid]>num[mid-1])
                    return mid;
              if(num[mid]<num[mid+1] && num[mid]>num[mid-1])
                    left = mid+1;
              if(num[mid]>num[mid+1] && num[mid]<num[mid-1])
                    right = mid-1;
              else
                    left = mid+1;

          }
      }
      return 0;
  }
};
