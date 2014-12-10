/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
  string longestPalindrome(string s) {
    if(s.size()<2)
      return s;
      int len = s.size();
      int i,j;
      bool dp[len][len];   // dp[][]表示s[i]...s[j]是否是palindrome

      memset(dp, 0, sizeof(dp));
      dp[0][0] = true;
      for(i=1;i<len;i++) {
        dp[i][i] = true;
      }

      // dp
      int max = 0;
      int start = 0;
      int end = 0;
      for(i=2;i<=len;i++) {      // i 代表子串的长度
          for(j=0;j<=len-i;j++) {  // j 代表子串起始位置
              int k = j+i-1;          // k 代表子串结束位置
              if(i==2)
                  dp[j][k] = (s[j]==s[k]);
              else
                  dp[j][k] = (s[j]==s[k]) && dp[j+1][k-1];

              if(dp[j][k] && i>max) {
                  max = i;
                  start = j;
                  end = k;
              }
          }
      }


      return s.substr(start,max);
    }
};
