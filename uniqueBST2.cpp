/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        if(n<1)
          return result;
        rec(result,1,n);
        return ;
    }

     void rec(vector<TreeNode *> &result, int start, int end) {
       if(start>end) {
         result.push_back(NULL);
         return result;
       }
       int i,j;
       for(i=start;i<=end;i++) {
         vector<TreeNode *> leftTree;
         rec(leftTree,start,i-1);
         vector<TreeNode *> rightTree;
         rec(rightTree,i+1,end);

         // 从底往上构造每个可能的解
         for(i=0;i<leftTree.size();i++) {
           for(j=0;j<rightTree.size();j++) {
             TreeNode *node = new TreeNode(i);
             node->left = leftTree[i];
             node->right = rightTree[j];

             result.push_back(node);
           }
         }
       }
    }
};
