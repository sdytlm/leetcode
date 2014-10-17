/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    void flatten(TreeNode *root) {
        if(root==NULL)
          return ;
        stack<TreeNode *> myStack;
        myStack.push(root);
        TreeNode *prev = NULL;
        while(!myStack.empty()) {
          TreeNode *Node = myStack.top();
          myStack.pop();
          if(prev!=NULL)
            prev->right = Node;

          if(Node->right!=NULL)
            myStack.push(Node->right);
          if(Node->left!=NULL)
            myStack.push(Node->left);

            prev = Node;
            Node->left =NULL;
            Node->right = NULL;
        }

        return ;
    }
};
