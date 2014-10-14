/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 *
 */

class Solution {

public:

	    int lengthOfLastWord(const char *s) {
				int result = 0;
				int length = 0;
				
				while(s[length]!='\0')
				    length++;
				if(length==0)
				  return result;
				int index = 0;
				while(index<length) {
					while(index<length && s[index]==' ') // Find the first non-whitespace character
						index++;
					if(index==length) // only whitespaces.
						return result;
					else
					    result = 0;
					while(index<length && s[index]!=' ') {
						result++;
						index++;
					}

				}
				return result;

	    }

};
