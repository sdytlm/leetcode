/* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

/**
 *
 * Definition for binary tree
 *
 * struct TreeNode {
 *
 *     int val;
 *     TreeNode *left;
 *
 *     TreeNode *right;
 *
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *
 *};
 *
 *         */

class Solution {

	public:

		    TreeNode *sortedArrayToBST(vector<int> &num) {
					if(num.size()==0)
					  return NULL;
				    return solution(num,0,num.size());

			}
			TreeNode *solution(vector<int> &num, int start, int end) {
				if(start>=end)
				  return NULL;
				int mid = start + (end-start)/2;
				TreeNode *result = new TreeNode(num[mid]);
				result->left = solution(num,start,mid);
				result->right = solution(num,mid+1,end);
				return result;
			
			}

};
