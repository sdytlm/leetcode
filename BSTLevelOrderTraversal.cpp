/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        
        vector<vector<int> > result;
        vector<int> row;
        queue< pair<TreeNode*, int> > nodes;
        
        if(root==NULL) {
            return result;
        }
        
        int level = 1;
        nodes.push(make_pair(root,1));
        while(!nodes.empty()) {
            // read queue
            TreeNode* curNode = nodes.front().first;
            int curLevel = nodes.front().second;
            nodes.pop();
            
            // input node to result
            // find same level node
            if(curLevel == level)
                row.push_back(curNode->val);
            else {                      // find next level node
                level = curLevel;
                result.push_back(row);
                // empty row
                while(!row.empty())
                    row.pop_back();
                // push curNode into new row
                row.push_back(curNode->val);
            }
            
            // push curNode->left and curNode->right into queue
            
            if(curNode->left!=NULL)
                nodes.push(make_pair(curNode->left,curLevel+1));
            if(curNode->right!=NULL)
                nodes.push(make_pair(curNode->right,curLevel+1));
        }
        result.push_back(row);
        
        return result;
    }
};