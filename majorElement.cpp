/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        if(num.size()==1)
            return num[0];
        unordered_map <int,int> hash;
        int n = num.size();
        int i;
        unordered_map <int, int> :: iterator it;
        for(i=0;i<n;i++) {
              it = hash.find(num[i]);
              if(it!=hash.end()) {
                    if(it->second >= n/2)
                          return it->first;
                    else
                       (it->second)++;
              }
              else
                hash.insert(make_pair(num[i],1));
        }
    }
};
