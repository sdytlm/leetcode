/* Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. 
 *
 * Input:Digit string "23" 
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]. 
 *
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;


string symbol[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution {

public:
	    vector<string> letterCombinations(string digits) {
            vector<string> result; 
			dfs(result,digits,0,"");  // 0是第几个digit
			return result;
		        
	    }

		void dfs(vector<string> &result,string digits, int curIndex,string tmpString) {
				if(curIndex == digits.size()) {  // Find a solution
                      result.push_back(tmpString);
					  return ;
				}

				int i=0;
				int digit = digits[curIndex]-'0';
				while(i<symbol[digit].size()){
					tmpString += symbol[digit][i];
					dfs(result,digits,curIndex+1,tmpString);
					tmpString = tmpString.substr(0,tmpString.size()-1);
					i++;
				}
				return ;
				
			

		}

};

int main()
{
	Solution sol;
	string digits = "2";
	sol.letterCombinations(digits);
	return 0;
}
