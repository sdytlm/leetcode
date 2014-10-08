/* Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 *  return [1,3,2].
 *
 */

/**
 *
 * Definition for binary tree
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

     vector<int> inorderTraversal(TreeNode *root) {
     vector<int> result;
     stack<TreeNode *> s;
     if(root==NULL)
       return result;
     s.push(root);
     while(!s.empty()) {
      TreeNode *node = s.top();
      // left tree is not empty
      if(node->left!=NULL) {          // check left child first.
        s.push(node->left);           // After you push left child, disconnect node with its left tree. otherwise, you will not end the loop.
        node->left = NULL;
      }
      // push_back current node if left is empty
      else { 
          result.push_back(node->val);           // parent node is checked before right child
          s.pop();
          // push right tree if it's not empty;  // right child
          if(node->right!=NULL)
          s.push(node->right);
      }
     }
     return result;
          
      }

};



