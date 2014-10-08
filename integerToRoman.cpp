/* Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 *
 */

class Solution {

public:
	    string intToRoman(int num) {
			const int radix[] = {1000, 900, 500, 400, 100, 90,
				50, 40, 10, 9, 5, 4, 1};
			const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
				"L", "XL", "X", "IX", "V", "IV", "I"};
			string result ="";
			int i;
			int len = 13;
			for(i=0;i<len;i++) {
				while(num>=radix[i]) {
					num -= radix[i];
					result += symbol[i];
				}
			}
			return result;
		        
	    }

};
