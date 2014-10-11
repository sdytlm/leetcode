/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

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
    int result = 0;
    bool hasPathSum(TreeNode *root, int sum) {
          if(root==NULL)
            return false;
          if(root->left == NULL && root->right == NULL){ // "root" is a leaf
              if(result+root->val== sum)
                return true;
              else
                return false;
          }
          result += root->val;
          // 遍历左右子树
          if(root->left != NULL && hasPathSum(root->left,sum))
            return true;
          if(root->right != NULL && hasPathSum(root->right,sum))
            return true;

          result -= root->val;  // 找不到一条经过"root"的路径，其长度为sum
          return false;
    }
};
