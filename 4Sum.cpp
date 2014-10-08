/* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)

*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        int a,b,c,d; // four elements
        if(num.size()<4)
            return result;
        sort(num.begin(),num.end());
        for(a=0;a<num.size();a++){
            for(b=a+1;b<num.size();b++){    //b=a+1
                c=b+1;
                d=num.size()-1;
                while(c<d){
                    int sum = num[a]+num[b]+num[c]+num[d];
                    if(sum==target){
                        vector<int> tmp;
                        tmp.push_back(num[a]);
                        tmp.push_back(num[b]);
                        tmp.push_back(num[c]);
                        tmp.push_back(num[d]);
                        result.push_back(tmp);
                        c++;
                        d--;
                        while(c<d && num[c]==num[c-1]) // c skip duplicates
                            c++;
                        while(c<d && num[d]==num[d+1]) // d skip duplicates
                            d--;
                    
                    }
                    else if (sum<target){
                        c++;
                        while(c<d && num[c]==num[c-1]) // c skip duplicates
                            c++;
                    }
                    else {
                        d--;
                        while(c<d && num[d]==num[d+1]) // d skip duplicates
                            d--;
                    }
                }
                while(num[b]==num[b+1]) // b skip duplicates
                    b++;
            }
            while(num[a]==num[a+1]) // a skip duplicates
                a++;
        }
        return result;
    }
};