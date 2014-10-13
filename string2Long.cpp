/*
 * Author: Min Li
 * Discussion:
 *    1. Return 0 when input is not valid (Empty or wrong format)
 *    2. Return LONG_MAX when input string overflows
 *    3. Return LONG_MIN when input string underflows
 *    4. Input String is allowed to have additional character after a valid substring that can form a long number. (e.g. +123+)
 *    5. Input can have many whitespaces before the first non-whitespace character. (e.g. "    123")
 *
 */


// Class: Solution

class Solution {
public:
	// Method: Convert String to Long
	long stringToLong(string s) {
		// Special Case: Empty
		if(s.size()==0)
		  return 0;
		long sign;                                          // Record the sign of the long number
		int index=0;
		int strLen = s.size();                              // The length of input
		long result=0;                                      // The final result
		// Discard the whitespaces before the first non-whitespace.
		while(index<strLen && s[index]==' ') index++;

		// The input only contains whitespaces
		if(index==strLen)
		  return 0;

		// Determine the sign
		if(s[index]=='-') {                                 // Input starts with "-"
		  sign = -1;
		  ++index;
		}
		else if(s[index]=='+') {                            // Input starts with "+"
		  sign = 1;
		  ++index;
		}
		else if(s[index] < '0' || s[index] > '9')           // Invalid input
		  return 0;
		else                                                // Unsigned input
		  sign = 1;

		// Retrieve the digit after first non-whitespace character
		while(index<strLen) {
			if(s[index]>='0' && s[index]<='9') {                                          // New character is 0-9
				int digit = s[index]-'0';
				if(result>LONG_MAX/10 || (result==LONG_MAX/10 && digit>LONG_MAX%10)) {	  // Overflow or underflow
					result = sign==-1?LONG_MIN:LONG_MAX;
				}
				else
				   result = result*10+digit;
			}
			else																		  // New character is not 0-9
                break;
			index++;
		}


		return sign*result;

	}
    
	// Method: Test
	void test() {
		string testString;
//		testString = "";						// Test Case 1: Empty
        testString = "123";						// Test Case 2: Valid unsigned input
//		testString = "+123";					// Test Case 3: Valid signed input
//		testString = "   123";                  // Test Case  : Valid input with whitespaces
//		testString = "abc123";                  // Test Case  : Invalid input
//		testString = "++123";					// Test Case 4: Invalid signed input
//		testString = "+123+";					// Test Case 5: Valid input format with additional characters
//		testString = "3924x8";					// Test Case 6: Invalid input format
//		testString = "1000000000000000000000";         // Test Case 7: Overflow
//		testString = "-10000000000000000000";          // Test Case 8: Underflow
	 cout << stringToLong(testString) << endl;
	}
};
