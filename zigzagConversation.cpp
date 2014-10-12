/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1||s.size()<=nRows)
          return s;
        string result = "";
        int gap = 2*(nRows-1);
        int i;
        // First rows
        int j;
        for(j=0;j<s.size();j+=gap){
            result+=s[j];
        }

        // 斜着的行
        for(i=1;i<nRows-1;i++) {
          int internal = 2*i;
          for(j=i;j<s.size();j+=internal) {
            result+=s[j];
            internal = gap-internal;
          }
        }

        // Last rows
        for(j=nRows-1;j<s.size();j+=gap) {
            result+=s[j];
        }
        return result;
    }
};
