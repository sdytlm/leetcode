/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> tmp;
        result.push_back(tmp); // 插入空集
        if(S.empty())
          return result;
        // 对S排序
        sort(S.begin(),S.end());
        res(result, tmp, S, 0);
        return result;
    }

    void res(vector<vector<int> > &result, vector<int> &tmp, vector<int> &S, int index) {
      int i;
      for(i=index;i<S.size();i++) {
        if(i==index || S[i]!=S[i-1]) { // 去掉重复
          tmp.push_back(S[i]);
          result.push_back(tmp);
          res(result,tmp,S,i+1);
          tmp.pop_back();
        }
      }
      return ;
    }
};
