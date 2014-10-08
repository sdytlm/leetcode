/* Given a roman numeral, convert it to an integer. 
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */


#include<iostream>
#include<string>

using namespace std;

class Solution {

public:

	      int romanToInt(string s) {
			
			int radix[] = {900, 400, 90, 40, 9, 4, 1000, 500, 100,50,10,5,1};
			string symbol[] = {"CM","CD","XC","XL","IX","IV","M","D","C","L","X","V","I"};
			int result = 0;
			int i;
			for(i=0;i<13;i++) {
				while(s.find(symbol[i])!=string::npos) {
					result += radix[i];
					s.erase(s.find(symbol[i]),symbol[i].size());
					cout << result << endl;
					cout << s << endl;
				}
			}
			return result;
	    }

};


int main()
{
	Solution sol;
	string s= "MMMDLXXXVI";
	sol.romanToInt(s);
	return 0;
}
