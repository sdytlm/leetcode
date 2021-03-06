/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

class Solution {
public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
      vector<vector<int> > result;
      if(num.size()==0)
          return result;
      sort(num.begin(), num.end());
      vector<int> tmp;
      dfs(result,tmp,num,target,0,0);
      // 去掉重复
      sort(result.begin(), result.end());
      result.erase(unique(result.begin(),result.end()),result.end());
      return result;
  }

  void dfs(vector<vector<int> > &result, vector<int> &tmp, vector<int> &num, int target, int index, int sum) {
      if(sum==target) {
          result.push_back(tmp);
          return ;
      }
      if(sum>target) {  //剪枝
          return ;
      }
      else {
          int i;
          for(i=index;i<num.size();i++) {
                tmp.push_back(num[i]);
                dfs(result,tmp,num,target,i+1,sum+num[i]);
                tmp.pop_back();
          }
      }
      return ;
  }
};
