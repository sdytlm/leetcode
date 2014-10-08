/* The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int i;
        string result;
        stringstream ss;
        k--;
        int *set = new int[n+1];
        for(i=1;i<=n;i++){	// create a set [1,2...n]
            set[i] = i;
        }
        for(i=n;i>0;i--){	// figure out every digit
            int factorial = 1;
            int j;
            for(j=1;j<i;j++){	// calculate (i-1)!
                factorial *= j;
            }
            int group = k/factorial;
            k = k%factorial;	// update k
            // Find the digit number for group
            j=1;
            int digit=0;
            int index=1;
            while(j <= group+1){
                if(set[index]!=-1){
                    digit = set[index];
                    j++;
		        }
                index++;
            }
            ss << digit;
            // Remove the number from set.
            set[index-1] = -1;
            
        }
        
        result = ss.str();
        return result;
        
        
    }
};

int main(){
    Solution sol;
    string result = sol.getPermutation(3,5);
    cout << result<<endl;
    return 0;
}