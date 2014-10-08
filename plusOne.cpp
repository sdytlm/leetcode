/* Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {

public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int>::iterator it;
		it = digits.end()-1;
		int sum = *it + 1;	
		int addon = 1;
		if(sum<10) {
		  *it = sum;
		  return digits;
		}
		else {
			*it = sum-10;
			it--;
			while(it>=digits.begin()) {
				int tmp = *it + addon;
				if(tmp<10) {
					*it = tmp;
					return digits;
				}
				else
				  *it = 0;
				it--;

			}
			digits.insert (it+1,1);
		}
		return digits;

	}

};

int main()
{
	Solution sol;
	vector<int> num;
	num.push_back(9);
	sol.plusOne(num);
	vector<int>::iterator it = num.begin();
	for(it=num.begin();it<num.end();it++)
	  cout << *it << endl;
	return 0;
}
