/* 
 * Author: Min Li
 * This code can implement insert and delete in a tri-nary tree.
 */

#include<iostream>

using namespace std;


// Definition for Tree Node
struct TreeNode {
public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode *middle;
		TreeNode(int x) : val(x), left(NULL), right(NULL), middle(NULL) {}
};


// Class: trinaryTree
class trinaryTree {
public:
	TreeNode* insert(TreeNode *root, int value);		// Insert a node
	TreeNode* deleteNode(TreeNode *root, int value);    // Delete a node
	TreeNode* findSuccessor(TreeNode *root);            // Find a node's successor
	bool test();                                        // Test my code
};


// Method: Insert a node into tri-nary tree
// return the root of new tri-nary tree
TreeNode* trinaryTree:: insert(TreeNode *root, int value) {
	TreeNode *Node = new TreeNode(value);
	if(root==NULL)					// tree is empty
	  root = Node;
	else {
	  TreeNode *parent;
	  TreeNode *tmpNode = root;
	  // Find the parent of "Node"
	  while(tmpNode!=NULL) { 
		parent = tmpNode;
		if(tmpNode->val < Node->val)		// Node is in the right subtree
		  tmpNode = tmpNode->right;
		else if(tmpNode->val > Node->val)	// Node is in the left subtree
		  tmpNode = tmpNode->left;
		else								// Node is in the middle subtree
		  tmpNode = tmpNode->middle;
	  }
	  // Insert the Node under parent
	  if(Node->val == parent->val)
		parent->middle = Node;
	  else if(Node->val > parent->val)
		parent->right = Node;
	  else
		parent->left = Node;
	}
	return root;
}

// Method: Delete a node from tri-nary tree
// Return the root of new tree
TreeNode* trinaryTree:: deleteNode(TreeNode *root, int value) {
		
	if(root==NULL)
	  return NULL;
	if(root->val == value) {
		if(root->left==NULL && root->middle==NULL && root->right==NULL) { // Delete a leaf
			delete root;
			return NULL;
		}
		if(root->middle!=NULL) {			// Middle child is not empty 
			root->middle = deleteNode(root->middle,value);
		}
		else {
			if(root->left==NULL) {			// Left child is empty, but right child is not
				TreeNode* rightChild = root->right;
				delete root;
				return rightChild;
				
			}
			else if(root->right==NULL) {	// Right child is empty, but left child is not
				TreeNode* leftChild = root->left;
				delete root;
				return leftChild;
			}
			else {	// Both left and right child exists
				TreeNode *successor = findSuccessor(root->right);
				root->val = successor->val;
				root->right = deleteNode(root->right,successor->val);
			}
		}
	}
	else if(root->val > value)  // Recursive left subtree
	  root->left = deleteNode(root->left,value);
	else						// Recursive right subtree
	  root->right = deleteNode(root->right,value);

	return root;
}

// Method: Find the successor
TreeNode* trinaryTree:: findSuccessor(TreeNode *root) {
	if(root->left==NULL)
	  return root;
	else
	  return findSuccessor(root->left);
}


// Method: Test
bool trinaryTree:: test() {
	trinaryTree test;
	TreeNode *root = NULL;
	TreeNode *node;
	
	// Test tree insert
	int val[] = {5,4,9,5,7,2,2};
	int i;
	for(i=0;i<sizeof(val)/sizeof(int);i++) {
		root = test.insert(root,val[i]);

	}
	
	// Test tree delete
	// Case1: delete a leaf
	test.deleteNode(root,5);
	// Case2: delete root
	test.deleteNode(root,5);
	// Case3: delete a node with only left child
	test.deleteNode(root,4);
	
	return true;


}

