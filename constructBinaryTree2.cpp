/* Given inorder and postorder traversal of a tree, construct the binary tree. 
 *
 */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

public:

	    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

		        TreeNode *root = dfs(inorder, postorder.size()-1, postorder, 0, inorder.size()-1);
	    }

		TreeNode *dfs(vector<int> &inorder, int rootIndex, vector<int> &postorder, int startInorder, int endInorder) {
			
			if(startInorder > endInorder)
			  return NULL;

			// 
			TreeNode *node = new TreeNode(postorder[rootIndex]);


			if(startInorder == endInorder)
			  return node;
			// Find postorder[rootIndex+1] 在inorderorder里的位置
			
			int i;
			for(i=startInorder; i<=endInorder;i++) {
				if(inorder[i] == postorder[rootIndex])
					break;
			}
			int subroot = i;

			node->right = dfs(inorder, rootIndex-1, postorder, subroot+1, endInorder); // postorder里紧挨着rootindex的是右子树的根
			node->left = dfs (inorder, rootIndex - (endInorder-subroot)-1, postorder, startInorder,subroot-1);       // endInorder-subroo是右子树的长度

			return node;

		}


};
