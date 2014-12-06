/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
  int findMin(vector<int> &num) {
      // Simple solution
      // sort(num.begin(),num.end());
      // return num[0];

      int left = 0;
      int right = num.size()-1;
      if(num[0]<num[right])
          return num[0];

      // 二分查找
      while(left!=right) {
          int pivot = (right+left)/2;
          if(num[pivot]>num[right])
              left = pivot+1;
          else
            right = pivot;

      }
      return num[left];

  }
};
