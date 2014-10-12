class Solution {
public:
    int atoi(const char *str) {
        // Special Case: Empty
		int strLen = strlen(str);
		if(strLen==0)
		  return 0;
		int sign;								// Record the sign of the long number
		int index=0;
							// The length of input
		int result=0;                          // The final result
		// Discard the whitespaces before the first non-whitespace.
		while(index<strLen && str[index]==' ') index++;
		
		// The input only contains whitespaces
		if(index==strLen)
		  return 0;

		// Determine the sign 
		if(str[index]=='-') {                      // Input starts with "-"
		  sign = -1;
		  ++index;
		}
		else if(str[index]=='+') {                 // Input starts with "+"
		  sign = 1;
		  ++index;
		}
		else if(str[index] < '0' || str[index] > '9') // Invalid input
		  return 0;
		else									// Unsigned input 
		  sign = 1;

		// Retrieve the digit after first non-whitespace character
		while(index<strLen) {
			if(str[index]>'0' && str[index]<'9') {                                          // New character is 0-9
				int digit = str[index]-'0';
				if(result>INT_MAX/10 || (result==INT_MAX/10 && digit>INT_MAX%10)) {	// Overflow or underflow
					result = sign==-1?INT_MIN:INT_MAX;
					break;
				}
				else
				   result += result*10+digit;
			}
			else																		// New character is not 0-9                                          
			  break;
			index++;
		}
		

		return sign*result;
    }
};
