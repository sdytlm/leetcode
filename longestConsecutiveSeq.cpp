/*Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*/


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map <int, bool> used; // hash map "used" will record if num[a] is checked. unordered_map is the STL template to implement hash map
        for(auto i:num)
            used[i] = false;    // add num[a] into hash map. i = num[a].
        int longest = 0;
        for(auto i:num) // Find the longest consecutive sequence.
        {
            if(used[i] == true) // element i has been checked before
                continue;
                                // find the unchecked element i;
            int length = 1;     // record the sequence length for current unchecked element.
            for(int j = i+1; used.find(j)!= used.end(); j++) // mark all consecutive elements > i as true. and increase the current sequence length.
            {
                used[j] = true;
                length++;
            }
            for(int j = i-1; used.find(j)!= used.end(); j--) // mark all consecutive elements < i as true. and increase the current sequence length.
            {
                used[j] = true;
                length++;
            }
            longest = longest>length? longest:length; // compare the global longest and current longest sequence.
            
        }
        return longest;
        
    }
};

