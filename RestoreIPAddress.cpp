/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    vector<string> ip;
    if(s.empty())
        return result;
        if(s.size()>=4 && s.size()<=12)
            dfs(result,ip,s,0);
        return result;
  }

  void dfs(vector<string> &result, vector<string> &ip, string s, int index) {
      if(ip.size()>=4){              // 这个退出的判断很重要，必须这么写，因为有时候ip的长度已经超过4了，但是并没有遍历完所有s中的字符.
          if(index>=s.size()) {
              result.push_back(ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3]);
          }
          return ;
      }
      int len;                       // subIP 的长度
      for(len=1;len<=3;len++) {
          if(index+len<=s.size()) {   // 确保没有超出s.size()的范围
              string str = s.substr(index,len);
              if(len>1 && str[0]=='0')  // subIP的长度>2 但是 仍然以0开始，e.g. "02". 不符合要求
                  continue;
              int subIP =  atoi(str.c_str());              // string -> int
              if(subIP <=255){       // subIP在有效范围
                  ip.push_back(str);
                  dfs(result,ip,s,index+len);
                  ip.pop_back();
              }
          }
      }
      return ;
  }
};
