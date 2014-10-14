/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 * [2,4],
 * [3,4],
 * [2,3],
 * [1,2],
 * [1,3],
 * [1,4],
 * ]
 *
 */

class Solution {

public:
	    vector<vector<int> > combine(int n, int k) {
				
			vector<vector<int> > result;
			vector<int> oneSolution;
			dfs(result, oneSolution, n,k,1,0);
			return result;    
	    }

		void dfs(vector<vector<int> > &result, vector<int> &oneSolution, int n, int k, int curVal, int round) {
			if(round == k) {
				result.push_back(oneSolution);
				return ;
			}
			int gap = 0;
			if(round<k) {
				int i;
				for(i=curVal;i<=n;i++) {
					oneSolution.push_back(i);
					dfs(result,oneSolution,n,k,i+1,round+1);
					oneSolution.pop_back();
				}
			}
			return ;
		
		}

};
