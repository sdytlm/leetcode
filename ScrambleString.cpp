/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

great
/    \
gr    eat
/ \    /  \
g   r  e   at
/ \
a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

rgeat
/    \
rg    eat
/ \    /  \
r   g  e   at
/ \
a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

rgtae
/    \
rg    tae
/ \    /  \
r   g  ta  e
/ \
t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

*/
#include<iostream>
using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {

    if(s1.size()!=s2.size())
        return false;
    if(s1.size()==0 && s2.size()==0)
        return true;
    const int len = s1.size();
    bool ***dp;   // 从s1[i]和s2[j]开始，长度为k的两个子串，是否是scramble.
    dp = new bool**[len];
    int i,j,k;
    // 初始化数组
    for(i=0;i<len;i++) {
        dp[i] = new bool*[len];
        for(j=0;j<len;j++) {
            dp[i][j] = new bool[len+1];
            for(k=1;k<=len;k++)
              dp[i][j][k] = false;
            dp[i][j][0] = true;
            dp[i][j][1] = s1[i]==s2[j]?true:false;
        }
    }

    // dp
    for(k=2;k<=len;k++) {
        for(i=0;i<=len-k;i++) {
            for(j=0;j<=len-k;j++) {
                int d;        // d是两个长为k其实点分别为s1[i]和s2[j]的两个子串的分割点
                for(d=1;d<k && !dp[i][j][k];d++) {
                  dp[i][j][k] = (dp[i][j][d] && dp[i+d][j+d][k-d]) || (dp[i][j+k-d][d] && dp[i+d][j][k-d]);
                }
            }
         }
    }


    return dp[0][0][len];
  }
};

int main(){
    Solution sol;
    string s1="ab";
    string s2="ba";
    sol.isScramble(s1,s2);
    return 0;
}
