/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
*/
class Solution {
public:
  string convertToTitle(int n) {
      string result="";
      while(n!=0) {
          int digit = n%26;
          if(digit==0){      // z的情况
              digit = 26;
              n--;          // 用来处理52 (zz)
          }
          string tmp = "";
          tmp = digit-1+'A';
          result = tmp+result;
          n = n/26;
      }
      return result;
  }
};
