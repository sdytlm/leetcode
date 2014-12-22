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
  int strLen(string &s, int &start) {
      while(start<s.size() && s[start]=='0')
          ++start;
      int end = start;
      while(end<size() && s[end]!='.')
          ++end;
      return end-start;
  }



  int compareVersion(string version1, string version2) {
      int len1 = version1.size();
      int len2 = version2.size();
      int start1,start2;
      for(start1=0,start2=0; start1 < len1 || start2 < len2; ++start1, ++start2) {


  }
};
