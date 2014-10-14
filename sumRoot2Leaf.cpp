/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int result=0;
    int sumNumbers(TreeNode *root) {
          if(root==NULL)
            return 0;
          dfs(root,0);
          return result;
    }

    void dfs(TreeNode* node, int curVal) {
        if(node==NULL) {
          result += curVal;
          return ;
        }
        if(node->left==NULL && node->right==NULL) {
          curVal = 10*curVal + node->val;
        }
        if(node->left!=NULL)
          dfs(root->left,curVal);
        if(node->right!=NULL)
          dfs(root->right,curVal);
        return ;
    }
};
