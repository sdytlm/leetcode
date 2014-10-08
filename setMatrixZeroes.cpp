/* Given a m × n matrix, if an element is 0, set its entire row and column to 0. Do it in place. Follow up: Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution?
*/


class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        bool zeroesRow = false;
        bool zeroesCol = false;
        int i,j;
        
        // Check if the first row need zeroes
        for(i=0;i<colSize;i++) {
            if(matrix[0][i]==0) {
                zeroesRow = true;
                break;
            }
        }
        
        // Check if the first col need zeroes
        for(i=0;i<rowSize;i++) {
            if(matrix[i][0]==0) {
                zeroesCol = true;
                break;
            }
        }
        
        // Check other rows and cols except row1 and col1
        for(i=1;i<rowSize;i++) {
            for(j=1;j<colSize;j++) {
                if(matrix[i][j]==0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < rowSize; ++i) {
            for (int j = 1; j < colSize; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
            }
        }
        
        // Clear first row if needed
        if(zeroesRow) {
            for(i=0;i<colSize;i++)
                matrix[0][i] = 0;
        }
        
        // Clear first col if needed
        if(zeroesCol) {
            for(i=0;i<rowSize;i++)
                matrix[i][0] = 0;
        }
        
    }
};

