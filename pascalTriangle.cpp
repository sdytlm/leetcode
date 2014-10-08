/* Given numRows, generate the first numRows of Pascal's triangle.
 
 For example, given numRows = 5,
 Return
 
 [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> tmpRow;
        
        if（numRows==0)
            return result;
        
        int i;
        // Assign the first and second row as 1
        tmpRow.push_back(1);
        result.push_back(tmpRow);
        if(numRows==1)
            return result;
        tmpRow.clear();
        tmpRow.push_back(1);
        tmpRow.push_back(1);
        result.push_back(tmpRow);
        if(numRows==2)
            return result;
        
        // For other rows
        for(i=2;i<numRows;i++) {
            tmpRow.clear();
            tmpRow.push_back(1);   // first element;
            int j;
            for(j=1;j<i;j++) {
                tmpRow.push_back(result[i-1][j-1]+result[i-1][j]);  //a[i][j] = a[i-1][j-1]+a[i-1][j];
            }
            tmpRow.push_back(1);   // last element
            result.push_back(tmpRow);
        }
        return result;
    
    }
};