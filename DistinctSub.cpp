/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/
/* Recursive method: 超时
class Solution {
public:
    int result=0;
    int numDistinct(string S, string T) {
        if(S.empty() || T.empty())
          return 0;
        dfs(S,0,T,0);
        return result;
    }

    void dfs(string S, int indexS, string T, int indexT) {
      if(indexT == T.size()) { // Find a solution
        result ++;
        return ;
      }
      int i=indexS,j=indexT;

      while(i<S.size()) {
        if(S[i]==T[j]) {
          dfs(S,i+1,T,j+1);
        }
        if(i+1<S.size() && S[i+1]==T[j])
          dfs(S,i+2,T,j+1);
        i++;
      }
        return ;


    }
};
*/
#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
       int numDistinct(string S, string T) {
         int lenS = S.size();
         int lenT = T.size();
         if(lenS==0)
           return 0;
         if(lenT==0)
           return 1;

        int dp[lenS+1][lenT+1];
        memset(dp,0,sizeof(dp));
        int i,j;
        // Initialize dp
        for(i=0;i<=lenS;i++)
          dp[i][0] = 1;

        for(i=1;i<=lenS;i++) {
          for(j=1;j<=lenT;j++) {
            if(S[i-1] == T[j-1])
              dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            else
              dp[i][j] = dp[i-1][j];
           }
        }
        return dp[lenS][lenT];
       }
};

int main()
{
  Solution sol;
  cout << sol.numDistinct("b","b") << endl;
  return 0;
}
