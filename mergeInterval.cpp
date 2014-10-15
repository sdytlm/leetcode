/* Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 */



//  Definition for an interval.
  struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
  };

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {

public:

        vector<Interval> merge(vector<Interval> &intervals) {
			  vector<Interval> result;
              if(intervals.size()==0)
                return result;
              int minVal = pow(2,30);
              int maxVal = -pow(2,31);
              unordered_map<int, int> hash;
              int i;

              for(i=0;i<intervals.size();i++) { // store value in the hashmap
                int startIndex = intervals[i].start;
                int endIndex = intervals[i].end;
                while(startIndex<=endIndex) {
                  if(hash.find(startIndex)==hash.end())
                    hash[startIndex] = 1;
                  if(minVal > startIndex)
                    minVal = startIndex;
                  if(maxVal < startIndex)
                    maxVal = startIndex;
                  startIndex++;
                }
              }

              // Read the hashmap
        cout << minVal<<endl;
        cout << maxVal<< endl;
        while(minVal<=maxVal) {
                Interval tmp;
                while(hash.find(minVal)==hash.end()) // Find start
                  minVal++;
                tmp.start = minVal;

                while(hash.find(minVal)!=hash.end()) // find end
                  minVal++;
                tmp.end = minVal-1;
                result.push_back(tmp);

              }
              return result;
	    }

};

int main()
{
    vector<Interval> a;
    Interval i(1,3);
    a.push_back(i);
    Solution sol;
    sol.merge(a);
    return 0;
}
