/* Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *         /  \
 *        2    3
 *       / \    \
 *      4   5    7
 *  After calling your function, the tree should look like:
 *            1 -> NULL
 *           /  \
 *          2 -> 3 -> NULL
 *         / \    \
 *        4-> 5 -> 7 -> NULL
 */

#include<iostream>
using namespace std;

 // Definition for binary tree with next pointer.
  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
 
 

class Solution {

public:

       void connect(TreeLinkNode *root) {
			if(root==NULL)
			  return ;
			queue<TreeLinkNode *> q;
			// Assign all most right node point to NULL
			TreeLinkNode *prev = NULL;	// 用来遍历每一层
			q.push(root);
			q.push(NULL);			
			while(!q.empty()) {
				TreeLinkNode *node = q.front();
				q.pop();
				if(node!=NULL) {
				    if(node->left!=NULL)
					    q.push(node->left);
				    if(node->right!=NULL)
				        q.push(node->right);
				}
				else {
				    if(!q.empty())
				        q.push(NULL);
				}
				
				if(prev!=NULL)
				  prev->next = node;
				prev = node;

			}

	       return ; 
	    }

};
int main()
{
	Solution sol;
	TreeLinkNode *root = new TreeLinkNode(0);
	sol.connect(root);
	return 0;
}
