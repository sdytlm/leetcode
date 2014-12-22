/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

*/
class Solution {
public:
  vector<vector<string> > partition(string s) {
      vector<vector<string> > result;
      if(s.empty())
          return result;
      int len = s.size();
      bool **dp = new bool*[len]; // dp[i][j]表示 以s[i]开始，第j个字符是否是回文
      int i,j;
      // 初始化dp
      for(i=0;i<len;i++) {
        dp[i] = new bool[len+1];
        for(j=0;j<=len;j++) {
            dp[i][j] = 0;
        }
        dp[i][1] = 1; // dp[i][1]一定是1
      }
      // 动态规划填满dp
      for(j=2;j<=len;j++) {
          for(i=0;i+j<=len;i++) {
              if(j==2) { // dp[i][2] 只需要考虑 s[i]和s[i+1]
                  dp[i][j] = (s[i]==s[i+1]);
              }
              else  // 对于其他的dp[i][j], 首先确保s[i+1]....s[i+j-2] 是回文，并且s[i]和s[i+j-1]也相当
                  dp[i][j] = dp[i+1][j-2] && (s[i] == s[i+j-1]);
          }
      }

      // dfs生成所有的解
      vector<string> tmp;
      dfs(dp,result,tmp,s,0); // 从s[0]开始找

      return result;

  }
     void dfs(bool **dp, vector<vector<string> > &result, vector<string> &tmp, string s, int index) {
       int len = s.size();
       if(index>=len) {
          result.push_back(tmp);
          return;
       }
       int i;
       for(i=1;i<=len-index;i++) {
          if(dp[index][i]) {
              tmp.push_back(s.substr(index,i));
              dfs(dp,result,tmp,s,index+i);
              tmp.pop_back();
          }

       }

       return ;
     }
};
