/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;


vector<string> result;
vector<char> s;

class Solution {


public:
		vector<string> generateParenthesis(int n) {
			string oneSolution = "";
			if(n==0)
			  return result;
			dfs(oneSolution,0,2*n);
			return result;
	    }

		void dfs(string oneSolution, int curLevel, int n) {
			if(curLevel == n) {
				if(valid(oneSolution,n)){
					cout << oneSolution<<endl;
					result.push_back(oneSolution);
				}
				return;
			
			}

			oneSolution += "(";
			dfs(oneSolution,curLevel+1,n);
			oneSolution = oneSolution.substr(0,oneSolution.size()-1);
			oneSolution += ")";
			dfs(oneSolution,curLevel+1,n);
			oneSolution = oneSolution.substr(0,oneSolution.size()-1);
			
			return;

		}

		bool valid(string oneSolution, int n) {   // check if the solution is valid
			s.clear();
			int i;
			for(i=0;i<n;i++) {
				if(oneSolution[i] == '(')
				  s.push_back(oneSolution[i]);
				else {
					if(s.empty())
					  return false;
					s.pop_back();
				}
			}
			if(s.empty())
			  return true;
			else
			  return false;
		}

};

int main() {
	Solution sol;
	sol.generateParenthesis(2);
	return 0;
}
