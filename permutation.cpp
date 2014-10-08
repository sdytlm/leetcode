/*
 Given a collection of numbers, return all possible permutations.
 
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > permute(vector<int> &num) {
        if(num.size()==0)
            return result;
        vector<int> onePermutation;
        dfs(num,onePermutation,0);
    }
    void dfs(vector<int> &num, vector<int> &onePermutation, int times) {
        if(num.size() == times) { // find a solution
            result.push_back(onePermutation);
            return ;
        }
        int i;
        for(i=0;i<num.size();i++) {
            if(find(onePermutation.begin(), onePermutation.end(), num[i]) == onePermutation.end()) {
                onePermutation.push_back(num[i]);
                dfs(num,onePermutation,times+1);
                //recursive
                onePermutation.pop_back();
            }
        }
        return ;
        
    }
};

int main()
{
    Solution sol;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    sol.permute(num);
}