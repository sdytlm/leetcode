/* Given two binary trees, write a function to check if they are equal or not
 * Two binary trees are considered equal if they are structurally identical and the node have the same value
 */

/*
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
          if(p==NULL && q==NULL)
            return 1;
          if(p==NULL && q!=NULL)
            return 0;
          if(p!=NULL && q== NULL)
            return 0;
          
          
          if (p->val != q->val)
            return 0;
          
          return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
          
    }
};