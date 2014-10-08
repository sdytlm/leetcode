/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {

public:

	void nextPermutation(vector<int> &num){

		if (num.size()==0 || num.size()==1){
			return;
		}

			recursive(num,num.size()-2);
		return;

	}
	void recursive(vector<int>&num, int index) {
		if(index<0) {
		    sort(num.begin(),num.end());
		    return ;
		}
		if(num[index]>=num[index+1]){  // 目前子序列最大，继续寻找, 别忘记=,因为元素可能相同
			recursive(num,index-1);
			return ;
		}
		else {
			int j = num.size()-1;
			while(j>index && num[j]<=num[index]) // find the first element > num[index] 我们不要相同的元素
			    j--;
			swap(num[index],num[j]);	// swap index and the first element > num[index]
			sort(num.begin()+index+1, num.end());
			return ;
		}
	}

};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	Solution sol;
	sol.nextPermutation(num);
//	sort(num.begin()+1,num.end());
	cout << num[0]<< " " << num[1]<<endl;
	return 0;
}
