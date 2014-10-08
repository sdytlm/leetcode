/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *     [10, 11, 16, 20],
 *       [23, 30, 34, 50]
 *       ]
 *       Given target = 3, return true.
 *
 */

class Solution {
    
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int first=0;
        int last = row*column;
        while(first<last) {
            int mid = first + (last-first)/2;
            int midNode = matrix[mid/column][mid%column];    // 注意这里
            if(target == midNode)
                return true;
            if(target > midNode)
                first = mid+1;
            else
                last = mid;                                 // 还有这里的last
        }
        return false;
        
    }
    
};