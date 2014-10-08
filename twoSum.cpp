/* Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {

public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		
		unordered_map<int,int> array;
		int i;
		for(i=0;i<numbers.size();i++) { // Insert the numbers and their index into the hashmap
			array[numbers[i]] = i;
		}

		vector<int> res;

		for(i=0;i<numbers.size();i++)
		{
			int dif = target - numbers[i];
			if (array.find(dif) != array.end()){
				// When duplicate
				if(dif==numbers[i]) // make sure dif appear twice in numbers[];
				{
					int j=0;
					int count=0;
					while(j<numbers.size()){
						if(dif==numbers[j])
							count++;
						j++;
					}
					if(count==1)
						continue;
		
				}
				res.push_back(i+1);
				res.push_back(array[dif]+1);
			}
			
		}

		return res;
	}

};



