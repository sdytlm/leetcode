/* Given binary tree {3,9,20,#,#,15,7},
 *      3 
 *     / \
 *    9  20
 *      /  \
 *     15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
 *
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
			vector<vector<int> > result;
			if(root==NULL)
			  return result;
			queue<pair<TreeNode*, int>> q;
			vector<int> tmp;
			int level = 1;

			// Push each with level node into queue 
			q.push(make_pair(root,1));
			while(!q.empty()) {
				TreeNode *curNode = q.front().first;
				int curLevel = q.front().second;
				q.pop();

				
				if(level == curLevel) {
					tmp.push_back(curNode->val);
				}
				if(level != curLevel) {
					level = curLevel;
					result.push_back(tmp);
					// clear tmp;
				    tmp.clear();
					tmp.push_back(curNode->val);
				}
				// Push left or right child
				if(curNode->left != NULL)
				  q.push(make_pair(curNode->left, curLevel+1));
				if(curNode->right != NULL)
				  q.push(make_pair(curNode->right, curLevel+1));
			
			}
			// last level;
			result.push_back(tmp);
			
			vector<vector<int> > res;
			int i;
			for(i=result.size()-1;i>=0;i--) {
				res.push_back(result[i]);
			}
			return res;
	    }

};
