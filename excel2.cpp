/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28

*/
class Solution {
public:
    int titleToNumber(string s) {
        int i;
        int index=0;
        int result=0;
        for(i=s.size()-1;i>=0;i--) {
            result += (s[i]-'A'+1)*pow(26,index++);
        }
        return result;
  }
};
