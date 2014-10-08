/*
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *
 */

/*
 *
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
	    int minDepth(TreeNode *root) {
			if(root==NULL)
			  return 0;
    
			stack<pair<TreeNode*, int> > s;
			s.push(make_pair(root,1));
			int result = pow(2,30);

			while(!s.empty()) {
				TreeNode *tmp = s.top().first;
				int len = s.top().second;
                s.pop();

				// push left child and right child
				if(tmp->left!=NULL)
				  s.push(make_pair(tmp->left, len+1));
				if(tmp->right!=NULL)
				  s.push(make_pair(tmp->right, len+1));
				if(tmp->left==NULL && tmp->right==NULL)
					result = min(result,len);

			
			}
		    return result;

		}

};
