/* Given a binary tree, return the preorder traversal of its nodes' values.
 
 For example:
 Given binary tree {1,#,2,3},
 1
 \
 2
 /
 3
 return [1,2,3].
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==NULL)
            return result;
        stack<TreeNode *> s;             // 用stack帮助实现  根-》左-》右
        s.push(root);
        
        while(!s.empty()) {
            TreeNode *tmp = s.top();
            result.push_back(tmp->val);
            s.pop();
            if(tmp->right!=NULL)        // 先压右孩子再压左孩子，这样就是根->左->右
                s.push(tmp->right);
            if(tmp->left!=NULL)
                s.push(tmp->left);
        }
        
        return result;
    }
};