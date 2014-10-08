/* Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 *
 *
 */
#include<iostream>
#include<string>
using namespace std;


class Solution {

public:
	    int minCut(string s) {
			if(s.size()<2)
			    return 0;
			
			int len = s.size();
			int *MIN = new int[len+1];    // minCut for each element
			int **p = new int *[len];    // 记录i,j是否是palindrome
			
			int i;
			int j;
			
			for(i=0;i<len;i++)    
			    p[i] = new int[len];

			for(i=0;i<len;i++)         // Initialize P[][]
			  for(j=0;j<len;j++)
				p[i][j] = 0;

			for(i=0;i<=len;i++){			// Initialize min[]
				MIN[i] = len-i;	
			    
			}
			for(i=len-1;i>=0;i--) {     
				for(j=i;j<len;j++) {
					if((s[i] == s[j]) && (j-i<2 || p[i+1][j-1]==1)) {
						p[i][j] = 1;
						MIN[i] = min(MIN[i], MIN[j+1]+1);
					}
										
				}
				
			
			}
			return MIN[0]-1; 
		      
		}

};


int main()
{
	Solution sol;
	string s = "ab";
	sol.minCut(s);
	return 0;
}
