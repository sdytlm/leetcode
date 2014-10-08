/* Implement int sqrt(int x). 
 * Compute and return the square root of x.
 *
 */

#include<iostream>
#include<math.h>
using namespace std;


class Solution {

public:
	    int sqrt(int x) {
			if (x<2)
			    return x;
			int low = 1;                          // 0不用考虑了
			int high = x;                         // 结果不可能有x大
			int result;
			while(high>=low) {
				result = low+ (high-low)/2;
				if(x/result == result)        // 不能用result*result,会溢出 
				  return result;
				if(x/result>result) {
					low = result+1;       // 注意：别写错了，否则while无法退出
				}
				else
					high = result-1;      // 注意: 别写错了，否则while无法退出
				}
					
			return high;                          // 注意: 这里不是返回result， 因为当你无法出尽的时候我们要取result-1的数，这个数就是high
				        
	    }

};
