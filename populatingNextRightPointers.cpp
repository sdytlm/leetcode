/* Too long to list the problem.
 * LeetCode: Populating Next Right Pointers in Each Node.
 */

/*
 *
 * Definition for binary tree with next pointer.
 *
 * struct TreeLinkNode {
 *
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 *
 * };
 *
 */

class Solution {

public:
	    void connect(TreeLinkNode *root) {
			if (root==NULL)
			  return ;
			int i=0;
			int level = 0;

			TreeLinkNode *tmp = root;
			// Set up NULL for each right level.
			while(tmp!=NULL) {
				tmp->next = NULL;
				tmp = tmp->right;
			}

			tmp = root;
			while(tmp->left!=NULL) {
				TreeLinkNode *head = tmp;
				while(head!=NULL) {		// For each level, connect all sblings belong same parent
					head->left->next = head->right;
					head = head->next;
				}
				// Foe each level, connect all slbings belong different parent
				head = tmp;
				while(head!=NULL && head->next!=NULL) {
					head->right->next = head->next->left;
					head = head->next;
				}
				tmp = tmp->left;
	    }
			return ;

};
