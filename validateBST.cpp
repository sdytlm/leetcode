/* Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 */

class Solution {

public:
	    bool isValidBST(TreeNode *root) {
			
			return isValid(root,pow(2,30),-pow(2,30));	        
	    }
	    
	    bool isValid(TreeNode *root, int upper, int lower){
	        if(root==NULL)
			      return true;
		    if(root->val>=upper || root->val <= lower)
		            return false;
			
		      return (isValid(root->left,root->val,lower) && isValid(root->right,upper,root->val));
        }
};
