/* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 */

#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int> lefts;    // record the position of each non-matching"(" in s
			int result = 0;
			int lastPos = -1;    //  record the last position of ")"
            int tmplen=0;
			int i;
			for(i=0;i<s.size();i++) {
				if(s[i] == '(')  // find '('
				  lefts.push(i); // push position of '('
			    else {           // find ')'
					if(lefts.empty()) { // no match found
						lastPos = i;
					}
					else {               // find match
					    lefts.pop();
						if(lefts.empty())         // 总是一个{一个}
						    tmplen = i-lastPos;
						else
						    tmplen = i-lefts.top();            // 连续的{{出现比如{{}
						result = result>tmplen?result:tmplen;
					}
				
				}
			
			}
			return result;

    }
};



