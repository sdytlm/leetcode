/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
          return false;
        // 判断x的位数;
        int d = 1;
        int l = 1;
        while(x/d>=10) {
          d *= 10;
          l++;
        }
        int left;
        int right;
        int i=0;
        while(i<l/2){
          left = x/d;
          right = x%10;
          if(left!=right)
            return false;
          x = (x%d)/10; // 要把最左边和最右边都去掉
          d = d / 100;
          i++;
        }

        return true;

    }
};
