/*
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

*/

class Solution {
public:
  int compareVersion(string version1, string version2) {
      int len1 = version1.size();
      int len2 = version2.size();
      int i=0,j=0;
      while(version1[i] == '0' && i<len1)
          ++i;
      while(version2[j] == '0' && j <len2 )
          ++j;
      // 判断小数点前的部分
      while(i<len1 && j < len2 && version1[i]!='.' && version2[j]!='.') {
          if(version1[i]==version2[j]) {
              ++i;
              ++j;
          }
          else if (version1[i] > version2[j])
              return 1;
          else
              return -1;
      }



      // 判断小数点后的部分

  }
};
