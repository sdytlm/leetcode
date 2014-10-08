/* You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 *
 */


class Solution {

public:
	void rotate(vector<vector<int> > &matrix) {
		
		int i=0,j=0;
		int n=matrix[0].size();
		for(i=0;i<n-1;i++){		// First swap
			for(j=0;j<n-i-1;j++){
				swap(matrix[i][j],matrix[n-j-1][n-i-1]);  
			}
		}
		for(i=0;i<n/2;i++){
			for(j=0;j<n;j++){
				swap(matrix[i][j],matrix[n-i-1][j]);
			}
		}
	
	}

	void swap(int &a, int &b){
		int tmp = a;
		a = b;
		b = tmp;
	}

};
