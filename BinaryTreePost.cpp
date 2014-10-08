/* Given a binary tree, return the postorder traversal of its nodes' values.
 
 For example:
 Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
 return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==NULL)
            return result;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *curNode = s.top();
            if(curNode->left == NULL && curNode->right == NULL) {   // Only pop when you find a leaf
                result.push_back(curNode->val);
                s.pop();
            }
            if(curNode->right != NULL) {    // disconnect curNode and curNode->right
                s.push(curNode->right);
                curNode->right = NULL;
            }
            if(curNode->left != NULL) {    // disconnect curNode and curNode->left
                s.push(curNode->left);
                curNode->left = NULL;
            }
            
        }
        return result;;
        
        
    }
};