/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
      // 利用queue, 把""相邻""的string插入queue，直到找到end. 每一层用NULL来分割
      int result = 1;
      queue<string> Q;
      if(start==end)
          return 0;
      // 插入start和NULL来分层;
      Q.push(start);
      Q.push("");
      while(!Q.empty()){
          string cur = Q.front();
          Q.pop();

          if(cur==end)  // 找到相同
              return result;

          if(cur!="") {
              int i;
              for(i=0;i<cur.size();i++) { // 修改cur的每一个字母，在字典中找相邻的
                  char newChar;
                  for(newChar='a';newChar<='z';newChar++) {
                      if(cur[i]!=newChar) {
                          char tmp = cur[i];
                          cur[i] = newChar;
                          if(dict.find(cur)!=dict.end()) {  // 新组合的string 在字典里有
                            Q.push(cur);
                            dict.erase(cur);                // dict若不删除，会出现死循环
                          }
                          cur[i] = tmp;                     // 别忘记把cur[i]变回去
                      }
                  }

              }
          }
          else { // 遍历完一层了
            if(!Q.empty()) { // 没到结束
              result++;
              Q.push("");
            }
          }
      }
      return 0;

  }
};
