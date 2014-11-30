/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
          string result = "";
          if(strs.empty())  // empty
            return result;
          if(strs.size()==1) // 只有1个字符串
            return strs[0];

          int i,j;
          int index=0;
          // 找到最短的字符串
          for(i=1;i<strs.size();i++) {
            if(strs[i].size()<strs[index].size())
              index = i;
          }
          bool isEqual = true;
          // 根据最短串的每个字符判断其他字符的位置
          for(i=0;i<strs[index].size();i++) {
            for(j=0;j<strs.size();j++) {
              if(strs[index][i] != strs[j][i]) {
                isEqual = false;
                break;
              }
            }
            if(!isEqual)
              break;
            result += strs[index][i];
          }
          return result;
    }
};
