/* Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */

class Solution {

public:

	    vector<int> getRow(int rowIndex) {
			vector<int> row;
			int head = 1;
			int end = 1;
			int i;
			row.push_back(head);
			if(rowIndex==0)
			  return row;
			row.push_back(end);
			if(rowIndex==1)
			  return row;

			for(i=2;i<=rowIndex;i++) {
				int j;
				int oldRow = row[0];
				for(j=1;j<i;j++) {
					int tmp = row[j];
					row[j] += oldRow;
					oldRow = tmp;
				}
			
			    row.push_back(end);

			}

			return row;
				        

	    }

};

int main() {
	Solution sol;
	sol.getRow(8);
	return 0;
}
