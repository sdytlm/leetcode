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
            int lenH = strlen(haystack);
            int lenN = strlen(needle);
	
			cout << lenH << endl;
			cout << lenN << endl;
			int i,j;
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
	char s[] = {'a','a','a'};
	char b[] = {'a','a','a','a'};
	cout << sol.strStr(s,b);
	return 0;
}
