/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[

  [3],

  [1],

  [2],

  [1,2,3],

  [1,3],

  [2,3],

  [1,2],

  []
]

*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
          vector<vector<int> > result;
          vector<int> oneSolution;
          if(S.empty())
            return result;
          sort(S.begin(),S.end());

          dfs(oneSolution, result, S,0);
          return result;

    }

    void dfs(vector<int> &oneSolution, vector<vector<int> > &result, vector<int> &S, int step)
      {
        if(step == S.size()) { // Find one solution
          result.push_back(oneSolution);
          return ;
        }
        // Push S[step]
        oneSolution.push_back(S[step]);
        dfs(oneSolution,result,S,step+1);
        // Don't push S[step];
        oneSolution.pop_back();
        dfs(oneSolution,result,S,step+1);
        return ;
      }
};
