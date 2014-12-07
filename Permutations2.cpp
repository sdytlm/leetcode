/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/


class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
      vector<vector<int> > result;
      vector<int> tmp;
      sort(num.begin(),num.end());
      if(num.empty())
          return result;
      dfs(result,tmp,num);
      sort(result.begin(),result.end());
      result.erase(unique(result.begin(),result.end()), result.end());
      return result;


    }

  void dfs(vector<vector<int> > &result, vector<int> &tmp, vector<int> &num) {
      if(num.size()==0) {
        result.push_back(tmp);
        return ;
      }

      int i;
      for(i=0;i<num.size();i++) {
          if(i>0 && num[i]==num[i-1])
              continue;
          tmp.push_back(num[i]);
          int oldNum = num[i];
          num.erase(num.begin()+i); // 把num[i]删掉
          dfs(result,tmp,num);
          tmp.pop_back();
          num.insert(num.begin()+i,oldNum); // 把删掉的num[i]插入到原来位置

      }

  }

};
