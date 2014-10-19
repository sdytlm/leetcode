/* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 */

/**
 *
 * Definition for an interval.
 *
 * struct Interval {
 *
 *     int start;
 *
 *     int end;
 *
 *     Interval() : start(0), end(0) {}
 *
 *     Interval(int s, int e) : start(s), end(e) {}
 *
 * };
 *
 */

 bool comp(Interval a, Interval b) {
            return a.start<b.start;
        }

class Solution {

public:

	    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
					if(intervals.empty()) {
						intervals.push_back(newInterval);
						return intervals;
					}

					int oldStart;
					int oldEnd;
					int newStart = newInterval.start;
					int newEnd = newInterval.end;
					int i,j;
					// 确定newStart的位置
					for(i=0;i<intervals.size();i++) {
						oldEnd = intervals[i].end;
						if(newStart <= oldEnd)
						  break;
					}
				    if(i==intervals.size()) { // 所有的interval[i]都小于newInterval
						intervals.push_back(newInterval);
						return intervals;
					}
				
					// 确定newEnd的位置
					for(j=i;j<intervals.size();j++) {
						oldEnd = intervals[j].end;
						if(newEnd <= oldEnd)
						  break;
					}
                    
                    // No overlap
                    if(j==i && newEnd < intervals[i].start) {
                        intervals.push_back(newInterval);
                        sort(intervals.begin(), intervals.end(), comp);
                        return intervals;
                    }
                        
                        
                    // Overalp
					intervals[i].start = min(intervals[i].start, newStart); // newStart要么在intervals[i]内，要么在intervals[i]与intervals[i-1]之间

				
					if(j!=intervals.size()) { // newEnd要么在intervals[j]内，要么在intervals[j]与intervals[j-1]之间
						if(newEnd>=intervals[j].start) { //newEnd在intervals[j]内
						    intervals[i].end = max(intervals[j].end, newEnd);
						    intervals.erase(intervals.begin()+i+1, intervals.begin()+j+1); // 清理overlap
						}
						else { // newEnd在intervals[j]与intervals[j-1]之间
						    intervals[i].end = newEnd;
						    if(i<j-1)
						        intervals.erase(intervals.begin()+i+1, intervals.begin()+j); // 清理overlap
						}
						
					}
					else { // newEnd是intervals里最大的.
						intervals[i].end = newEnd;
						intervals.erase(intervals.begin()+i+1, intervals.end()); // 清理overlap
					}
					return intervals;
	    }

};
