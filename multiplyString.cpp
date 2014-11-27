/*Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.*/

// Example program
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int sign1 = 1;
    int sign2 = 1;
    if(num1=="0"||num2=="0")
        return "0";
    if(num1[0]=='-') {
      sign1 = -1;
      num1.erase(0,1);
    }
    if(num2[0]=='-') {
      sign2 = -1;
      num2.erase(0,1);
    }
    int i,j,k=0;
    string result = "";
    for(i=num1.size()-1;i>=0;i--) {
      string tmp = "";
      int addin = 0;
      // 得到num1[i]*num2的结果
      for(j=num2.size()-1;j>=0;j--) {
        int res = (num2[j]-'0')*(num1[i]-'0')+addin;
        tmp += to_string((res)%10);
        addin = (res)/10;
      }
      if(addin != 0)
        tmp += to_string(addin);

        // Add tmp and result
        //cout << tmp << endl;
        result = addTwo(tmp, result,k++);
      //  cout << result << endl;
      }
      // Generate the final result
      string final_result="";
      if(sign1*sign2<0)
          final_result += "-";
      for(i=result.size()-1;i>=0;i--){
          final_result += result[i];
      }
         cout << final_result.size()<<endl;
      return final_result;
    }

    string addTwo(string str1, string str2, int offset){
      //cout << str1 << endl;
      //cout << str2 << endl;
      //cout << offset << endl;
      string result="";
      int i,j=0;
      // 把空位的挪到result里
      for(i=0;i<offset;i++)
        result += str2[i];

        // 剩下的相加
        int addin = 0;
        // str2 is longer than str1
      for(i=offset;i<str2.size();i++) {
          int tmp;
          if(j<str1.size())
            tmp = (str2[i]-'0')+(str1[j++]-'0')+addin;
           else
            tmp = (str2[i]-'0')+addin;
            result+= to_string(tmp%10);
            addin = tmp/10;

        }
        // str1 is longer than str2
        while(j<str1.size()) {
            int tmp;
            tmp = (str1[j]-'0')+addin;
            result += to_string(tmp%10);
            addin = tmp/10;
            j++;
        }
        // 把addin加上去;
        if(addin!=0)
            result += to_string(addin);
            return result;
        }

    };

int main(){
    Solution sol;
    sol.multiply("0","0");
}
