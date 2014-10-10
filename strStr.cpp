/* Implement strStr().
 *
 * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 *
 */
#include<iostream>
#include<string>
using namespace std;

class Solution {

public:

	    char *strStr(char *haystack, char *needle) {
				if (!*needle) return (char *)haystack;
                else if (!*haystack) return NULL;


			int i=0,j;
			int lenH=0,lenN=0;
			// Calculate the length
			while(haystack[i++]!='\0')
				lenH++;
			i=0;
			while(needle[i++]!='\0')
				lenN++;
			// Compare haystack[i+j] and needle[j]	
			for(i=0;i<lenH-lenN+1;i++) {
				for(j=0;j<lenN;j++){
				    if(haystack[i+j] != needle[j]) {
							break;
						}
				  }
				  if(j==lenN)
				    return (char *)(haystack+i);
			}
			return NULL;

        }

};


int main() {
	Solution sol;
	char s[] = "aaa";
	char b[] = "aaaa";
//	cout << sizeof(s) << endl;
	cout << sol.strStr(s,b);
	return 0;
}
