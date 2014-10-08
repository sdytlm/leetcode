/* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 *
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.size()<2)
            return 0;
        int first = 0;
        int last = height.size()-1;
        int max=0;
        while(first<last) {
            int tmp;
            if(height[first]<height[last]) {
                tmp = (last-first) * height[first];
                first ++;
            }
            else {
                tmp = (last-first) * height[last];
                last--;
            }
            max = max>tmp?max:tmp;
        }
        return max;
    }
};
