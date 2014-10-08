/* Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {

public:

	    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
			vector<vector<int> > result;
			vector<int> intermediate;
			int i;
			sort(candidates.begin(),candidates.end());
			for(i=0;i<candidates.size();i++) {
				intermediate.clear();
				intermediate.push_back(candidates[i]);
				if(target>=candidates[i]) 
					dfs(candidates,result,intermediate,target-candidates[i],i);
			}
			return result;

				        
	    }

		void dfs(vector<int> &candidates, vector<vector<int> > &result, vector<int> &intermediate, int gap, int startIndex) {
			if(gap==0) {
				result.push_back(intermediate);
				return ;
			}
			else {
				int i;
				// try all possibile candidates[i];
				for(i=startIndex; i<candidates.size(); i++) {
					if(candidates[i] <= gap) {
						intermediate.push_back(candidates[i]);
						dfs(candidates,result,intermediate,gap-candidates[i],i);

					    intermediate.pop_back();

					}
					else
					  return ;
				
				}

			}

		}

};

int main()
{
	Solution sol;
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	vector<vector<int> > res =	sol.combinationSum(candidates,7);
	int i;
	for(i=0;i<res[1].size();i++) 
	  cout << res[1][i] << endl;
}
