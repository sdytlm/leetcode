/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

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
 #include <iostream>
 #include <vector>
 #include <unordered_map>

 using namespace std;

 struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
  /* 本地跑过了，oj不行
    vector<vector<int> > result;
    unordered_map<TreeNode*, int> hash;
    if(root==NULL) {
      return result;
    }

    hash.insert(make_pair(root,0));
    vector<int> tmp;
    int level = 0;

    while(!hash.empty()){
      tmp.clear();
      // copy node values into tmp;
      unordered_map<TreeNode*, int> :: iterator it;
      if(level%2==0) {  // 偶数行
        for(it=hash.begin();it!=hash.end();it++) {
          tmp.push_back((it->first)->val);
        }
      }
      else { // 奇数行
        for(it=hash.begin();it!=hash.end();it++) {
          tmp.insert(tmp.begin(),(it->first)->val);
        }
      }
      result.push_back(tmp);

      // Update hash table
      level++;
      for(it=hash.begin();it!=hash.end();it++) {
        if(it->second!=level) {
          // left tree is not empty
          if((it->first)->left!=NULL)
            hash.insert(make_pair((it->first)->left,level));
            // right tree is not empty
            if((it->first)->right!=NULL)
              hash.insert(make_pair((it->first)->right,level));
            }
            // delete current node
            hash.erase(it);
          }

        }
        int i,j;
        for(i=0;i<result.size();i++) {
          for(j=0;j<result[0].size();j++)
            cout << result[i][j]<<endl;
        }
        return result;
*/

// 用两个栈实现,依次往s1,s2插入，一个先插左子树再右子树，一个先插右子树再左子树，最后就能得到zigzag的遍历效果
    vector<vector<int> > result;
    vector<int> tmp;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    s1.push(root);
    bool isS1 = true;
    while(s1.empty() || s2.empty()) {
          if(isS1) { // s1 非空
            TreeNode *node = s1.top();
            s1.pop();
            tmp.push_back(node->val);
            if(node->left) s2.push(node->left); //先左子树再右子树
            if(node->right) s2.push(node->right);
            if(s1.empty()) { // s1 读完了
                result.push_back(tmp);
                isS1=false;
                tmp.clear();
            }
          }
          else { // s2 非空
            TreeNode *node = s2.top();
            s2.pop();
            tmp.push_back(node->val);
            if(node->right) s1.push(node->right); // 先右子树再左子树
            if(node->left) s1.push(node->left);
            if(s2.empty()) { // s2 读完了
              result.push_back(tmp);
              isS1 = true;
              tmp.clear();
            }
          }
    }

    return result;
      }
  };

int main(){
  Solution sol;
  TreeNode *root = new TreeNode(1);
  TreeNode *node = new TreeNode(2);
  root->left = node;
  sol.zigzagLevelOrder(root);
  return 0;
}
