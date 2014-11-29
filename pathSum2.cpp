/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/* Definition for binary tree */

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if(root==NULL)
          return result;
        vector<int> tmp;
        traverse(root, result, tmp, sum, 0);
        return result;
    }

    void traverse(TreeNode *root, vector<vector<int> > &result, vector<int> &tmp, int sum, int cur)         {

      if(root->left==NULL && root->right==NULL){ // 找到一个path
        tmp.push_back(root->val);
        if(cur+root->val ==sum ) { // 正解
          result.push_back(tmp);
        }
        if(!tmp.empty())
            tmp.pop_back();
        return ;
      }
      else { // node
        tmp.push_back(root->val);
        cur += root->val;
        if (root->left!=NULL)
            traverse(root->left,result,tmp,sum,cur);
        if(root->right!=NULL)
            traverse(root->right,result,tmp,sum,cur);
        tmp.pop_back();
      }
      return ;

    }
};
