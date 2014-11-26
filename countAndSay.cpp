/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n < 1)return "";
        string prev = "1";
        for(int i = 2; i <= n; i++)
        {
            char curChar = prev[0];
            int times = 1;//curChar 出现的次数
            string tmpstr;
            prev.push_back('#');//处理边界条件
            for(int k = 1; k < prev.size(); k++)
            {
                if(prev[k] == curChar)
                    times++;
                else
                {
                    tmpstr += to_string(times);
                    tmpstr.push_back(curChar);
                    curChar = prev[k];
                    times = 1;
                }
            }
            prev = tmpstr;
        }
        return prev;
    }
};
