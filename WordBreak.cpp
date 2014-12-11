/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
          int strLen = s.size();
          bool *dp = new bool[strLen+1];
          int i;
          dp[0] = true;
          for(i=1;i<=strLen;i++)
              dp[i] = false;
          for(i=0;i<=strLen;i++) {                          // i把字符串分成s[0...i]和s[i...end],子串s[0...i]已经确定好了，只需要确定s[i...end]即可
              unordered_set<string>::iterator it;
              for(it=dict.begin();it!=dict.end();it++) {
                  if(dp[i]) {                              // 当s[0...i]在dict能找到时，再查找s[i+1...end]是否也能找到
                      int len = (*it).size();
                      if(i+len>strLen)
                          continue;
                      string tmp = s.substr(i,len);       // 读每个dict[],看看是否和s[i+1...end]中的某部分相等.
                      if(tmp==*it)
                          dp[i+len] = true;               // update dp[]
                  }

              }

          }
          return dp[strLen];
    }
};
