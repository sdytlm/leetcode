/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        // edge case
        if(word1.size()==0)
            return word2.size();
        if(word2.size()==0)
            return word1.size();
        
        // initialize dp[][];
        int lenA = word1.size();
        int lenB = word2.size();
        int **dp = new int*[lenA+1];
        int i,j;
        for(i=0;i<lenA+1;i++)
            dp[i] = new int[lenB+1];
        for(i=0;i<lenA+1;i++)
            dp[i][0]=i;
        for(i=0;i<lenB+1;i++)
            dp[0][i] = i;
        
        // dp
        for(i=1;i<lenA+1;i++) {
            for(j=1;j<lenB+1;j++) {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];  // matched!
                else {
                    int tmp = min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j] = min(dp[i-1][j-1],tmp)+1; // delete,replace or insert?
                }
            }
        }
        return dp[lenA][lenB];
    }
};