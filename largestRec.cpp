/* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram. 
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * For example,
 * Given height = [2,1,5,6,2,3], 
 * return 10.
 *
 */

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
          stack<int> asc;            // 维护递增的bar的index
		int maxSize=0;
		if(height.empty())
		  return 0;
		if(height.size()==1)
		  return height[0];
		int i;
		height[height.size()] = 0;    // Insert 0 as the last bar.
		for(i=0;i<height.size()+1;i++) {
			
			if(asc.empty())      // If stack is empty, push i
			  asc.push(i);
			else {
				if(height[i] >= height[asc.top()]) // stack is non-empty, but new bar is higher than current bar in stack
				  asc.push(i);
				else {    // new bar is lower than current bar in stack
					int h;
					while(!asc.empty() && height[i]<height[asc.top()])
					{	
						h = height[asc.top()];
						asc.pop();
					
					    int w = asc.empty()?i:i-asc.top()-1;
					    int s = w*h;
					    maxSize = maxSize>s?maxSize:s;
					    
					    
					}
                    
					
					asc.push(i);
				}
			}
		}
		return maxSize;
				       
    }
};
