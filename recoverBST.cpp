/* Two elements of a binary search tree (BST) are swapped by mistake.
 *
 * Recover the tree without changing its structure.
 *
 * Note:
 * A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
 */

class Solution {

public:
	    void recoverTree(TreeNode *root) {
		
			vector<TreeNode *> t;
			load(root,t); // load bst into an array
			int i;

			for(i=0;i<t.size()-1;i++) { // find first unordered element
				if(t[i]->val > t[i+1]->val)
				  break;
			}
			int firstIndex = i;

			for(i=t.size()-1;i>0;i--) { // find second unordered element
				if(t[i]->val < t[i-1]->val)
				  break;
			}
			int secondIndex = i;

			swap(t[firstIndex]->val, t[secondIndex]->val);
			return ;
		        
	    }

		void load(TreeNode *node, vector<TreeNode *> &t) {
			if(node == NULL)
			  return;
			load(node->left,t);
			t.push_back(node);
			load(node->right,t);
		
		}

};
