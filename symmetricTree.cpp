/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree is symmetric:
 
    1
  /   \
  2   2
 / \ / \
3  4 4  3
 But the following is not:
  1
 / \
2   2
 \   \
 3    3
*
*
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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
            return true;
        return dfs(root->left,root->right);
    }
    
    bool dfs(TreeNode *leftSubTree, TreeNode *rightSubTree) {
        if(leftSubTree == NULL && rightSubTree == NULL)
            return true;
        if(leftSubTree == NULL && rightSubTree != NULL)
            return false;
        if(leftSubTree != NULL && rightSubTree == NULL)
            return false;
        if(leftSubTree->val != rightSubTree->val)
            return false;
        return (dfs(leftSubTree->left, rightSubTree->right)) && (dfs(leftSubTree->right, rightSubTree->left));
    }
};