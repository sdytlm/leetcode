/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    const char *head = s;
    return rec(s,p,head);

  }


  bool rec(const char *s, const char *p, const char *head) {
    if(*s=='\0') // s为空匹配成功
      return true;

      if(*p=='\0' && *s!='\0') // p为空而s不是空 p不能匹配s
        return false;

        if(*p=='*'){
          if(*s==*(p-1) || *(p-1)=='.'){ // 被*的字母能匹配s中当前字母
            return (rec(s+1,p,head) || rec(s+1,p+1,head));
          }
          else { // 被*字母不能匹配s中当前字母
            return rec(head,p+1,head);
          }
        }

        // p和s都不为空
        if(*p==*s || *p=='.') {
          return rec(s+1,p+1,head);
        }
        else
          return rec(head,p+1,head);
        }
      };
