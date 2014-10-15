/* Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 */



//  Definition for an interval.
 
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
  };


bool comp(Interval a, Interval b) {
	return a.start<b.start;
}

class Solution {

public:

        vector<Interval> merge(vector<Interval> &intervals) {
			
			vector<Interval> result;
			if(intervals.size()==0 || intervals.size()==1)
			  return intervals;
	
			sort(intervals.begin(), intervals.end(),comp); // sort intervals according to .start
			result.push_back(intervals[0]);
			vector<Interval>::iterator it;
			for(it=intervals.begin()+1;it<intervals.end();it++) { // 若发现conflict则Update result里的.end;否则压栈
				Interval &prev = result.back();
				if(prev.end >= it->start) { // conflict
					prev.end = max(prev.end, it->end);
				}
				else
					result.push_back(*it);
			}
			
			  return result;
	    }

};



int main()
{
    vector<Interval> a;
    Interval i(1,4);
    Interval j(0,2);
	Interval k(3,5);
	a.push_back(i);
	a.push_back(j);
	a.push_back(k);
    Solution sol;
    sol.merge(a);
    return 0;
}
