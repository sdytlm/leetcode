/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * 
 * For example, given array S = {-1 0 1 2 -1 -4},
 * A solution set is:
 *         (-1, 0, 1)
 *         (-1, -1, 2)
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {

public:
		vector<vector<int> > threeSum(vector<int> &num) {
		
		vector<vector<int> > rst;
		if(num.size() < 3) {
			return rst;
		}
		sort(num.begin(),num.end());
		for (int i = 0; i < num.size() - 2; i++) {
			if (i != 0 && num[i] == num[i - 1]) {
				continue; // to skip duplicate numbers; e.g [0,0,0,0]
			}

			int left = i + 1;
			int right = num.size() - 1;
			while (left < right) {
				int sum = num[left] + num[right] + num[i];
				if (sum == 0) {
					vector<int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(num[left]);
					tmp.push_back(num[right]);
					rst.push_back(tmp);
					left++;
					right--;
					while (left < right && num[left] == num[left - 1]) { // to skip duplicates
						left++;
					}
					while (left < right && num[right] == num[right + 1]) { // to skip duplicates
						right--;
					}
				} else if (sum < 0) {
					left++;
				} else {
					right--;
				}
			}
		}
		return rst;
	}
};


int main()
{
	vector<int> in;
	in.push_back(-1);
	in.push_back(0);
	in.push_back(1);
	in.push_back(2);
	in.push_back(-1);
	in.push_back(-4);

	Solution sol;
	vector<vector<int> > ou = sol.threeSum(in);
	
	int i=0;
	int index=0;
	while(i<ou.size())
	{
		cout << ou[index][i] <<" " << ou[index][i+1]<<" " << ou[index][i+2]<<endl;
		index++;
		i=i+3;
	}


}
