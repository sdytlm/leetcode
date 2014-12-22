/*
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

*/

class Solution {
public:
  int compareVersion(string version1, string version2) {
        int i=0,j=0;
        while(i<version1.size() || j<version2.size()) {
            int num1=0;
            int num2=0;
            while(i<version1.size() && version1[i]!='.'){   // 计算小数点前部分或者小数点后部分的数
                num1 = 10*num1 + version1[i]-'0';
                i++;

            }
            while(j<version2.size() && version2[j]!='.'){   // 同上
                num2 = 10*num2 + version2[j]-'0';
                j++;
            }

            // 比较两个数
            if(num1 > num2)
                return 1;

            if(num1 < num2)
                return -1;

            i++;
            j++;

        }
        return 0;
  }
};
