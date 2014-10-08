/* Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 */ 

/**
 *
 * Definition for binary tree
 *
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 */

class Solution {

public:

	    bool isBalanced(TreeNode *root) {
			if(root==NULL)
			  return true;
			
			if(dfsHeight(root) == -1)
			  return false;
			else
			  return true;
	        
	    }

		int dfsHeight(TreeNode *node) {
			
			if(node==NULL) return 0;

			int left;
			int right;


			left = dfsHeight(node->left);
			right = dfsHeight(node->right);

			if(left<0 || right<0 || abs(left-right)>=2)  // left<0 和 right <0 用来保证底下传来的-1能顺利回到root点
			  return -1;
			return max(left,right)+1;

			
		}

};
