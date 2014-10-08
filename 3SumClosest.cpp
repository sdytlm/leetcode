/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *  For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 */


#include<iostream>
#include<math.h>
#include<vector>
#include<complex>
#include<algorithm>
using namespace std;

class Solution {

public:
	    int threeSumClosest(vector<int> &num, int target) {
			int diff=pow(2,30);
			int start;
			int result=0;
			sort(num.begin(),num.end());
			for(start=0;start<num.size();start++){
				int mid = start+1;
				int end = num.size()-1;
				while(mid < end){
					int sum = num[start]+num[mid]+num[end];
					
					if(diff>abs(target-sum)){
					  diff = abs(target-sum);
					  result = sum;
					}
					if(target == sum)
					  return sum;
					else if(target > sum){
						mid++;
						
					}
					else{	//target < sum
						end--;
						
					}
					  

				}
				
			}
				        
			return result;
	    }

};


int main()
{
	vector<int> num;
	num.push_back(0);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-3);
	Solution sol;
	int result =	sol.threeSumClosest(num,1);
	cout << result << endl;
	return 0;
}
