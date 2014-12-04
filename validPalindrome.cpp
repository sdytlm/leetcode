/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/

class Solution {
public:
  bool isPalindrome(string s) {
    if(s.empty())
      return true;
      int head = 0;
      int tail = s.size()-1;
      int i;
      for(i=0;i<s.size();i++) {
        if(s[i]<='Z' && s[i]>='A')
          s[i] = tolower(s[i]);
        }

        while(head<tail) {
          if((s[head]>='a'&& s[head]<='z') || (s[head]>='0'&& s[head]<='9'))  {
            if((s[tail]>='a'&& s[tail]<='z') || (s[tail]>='0'&& s[tail]<='9')) {  // 两个字符均有效
              if(s[head]!=s[tail])
                return false;
                head++;
                tail--;
              }
              else   // tail 无效
              tail--;
            }
            else // head 无效
            head++;
          }
          return true;
        }
      };
