/* Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 */
#include<iostream>
#include<string>
using namespace std;



class Solution {

public:
	    int lengthOfLongestSubstring(string s) {
			if(s.size()<2)
			  return s.size();
			int pos[256];                      // 记录一个字符上次出现的位置
			int len = 0;
			int start = 0;                    // 当前子串的起始位置
			int i;
			for(i=0;i<256;i++) {
				pos[i] = -1;
			}

			for(i=0;i<s.size();i++) {
				if(pos[s[i]] >= start) {  // s[i] appear in substring
					len = len>i-start?len:i-start;
					start = pos[s[i]]+1;
				}
			
					pos[s[i]] = i;
		
			}
			
				// consider when reach the last index
			len = len>i-start?len:i-start;
			return len;
		      
		}

};
int main()
{
	Solution sol;
	string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	int haha = sol.lengthOfLongestSubstring(s);
	cout << haha << endl;
}
