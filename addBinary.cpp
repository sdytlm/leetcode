/* Given two binary strings, return their sum (also a binary string).
* For example,
* a = "11"
* b = "1"
* Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int l1 = a.size();
        int l2 = b.size();
        int l = l1<l2?l1:l2;
        int i,j=l1-1,k=l2-1;
        for(i=0;i<l;i++) {
            int a1 = a[j--]-'0';
            int a2 = b[k--]-'0';
            int tmp = (a1+a2+carry)%2;
            carry = (a1+a2+carry)/2;
            result = to_string(tmp)+result;
            
        }
        // if a.size() < b.size()
        while(l1<l2 && k>=0) {
            int a2 = b[k--]-'0';
            int tmp = (a2+carry)%2;
            carry = (a2+carry)/2;
            result = to_string(tmp)+result;
        }
        // if a.size() > b.size()
        while(l1>l2 && j>=0) {
            int a1 = a[j--]-'0';
            int tmp = (a1+carry)%2;
            carry = (a1+carry)/2;
            result = to_string(tmp)+result;
        }
        if(carry==1)
            result = '1'+result;
        return result;
    }
};