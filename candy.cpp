/* There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 * 
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {

public:
    int candy(vector<int> &ratings) {
		vector<int> candy;
		int num = ratings.size();
		int i;
		int result=0;
		// Assign each child one candy
		for(i=0;i<num;i++) {
			candy.push_back(1);
		}

		// From left to right, assign child i an extra candy if ratings[i] > ratings[i-1] and candy[i] < candy[i-1]
		for(i=1;i<num;i++) {
			if(ratings[i]>ratings[i-1] && candy[i]<=candy[i-1]){
			  candy[i] = candy[i-1]+1;      // child i must have more candy than child i-1
			}
		}
		

		// From right to left, assign child i an extra candy if ratings[i] > ratings[i+1] and candy[i] < candy[i+1]

		for(i=num-2;i>=0;i--) {
			if(ratings[i]>ratings[i+1] && candy[i]<=candy[i+1]) {
			  candy[i]=candy[i+1]+1;	// child i must have more candy than child i+1
			}
		}

		// count how many candy does all children have

		for(i=0;i<num;i++) {
			result += candy[i];
		}
		return result;
    }

};

int main()
{
	Solution sol;
	vector<int> ratings;
	ratings.push_back(1);
	ratings.push_back(2);
	ratings.push_back(2);
	sol.candy(ratings);
	return 0;
}
