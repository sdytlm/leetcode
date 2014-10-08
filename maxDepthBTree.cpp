/*
 *Definition for binary tree
 *struct TreeNode {
 *   int val;
 *   TreeNode *left;
 *   TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */


class Solution {
public:
int maxDepth(TreeNode *root) 
{
// Note: The Solution object is instantiated only once and is reused by each test case.
         if(root==NULL)
			   return 0;
         int leftPart = maxDepth(root->left);
         int rightPart = maxDepth(root->right);
         return (leftPart > rightPart)? leftPart+1 : rightPart+1;
}
};
