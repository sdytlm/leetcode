// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
   TreeNode *sortedListToBST(ListNode *head) {
     int n = 0;
     if(head==NULL)
       return NULL;
       ListNode *tmp = head;
       while(tmp!=NULL) {
         tmp = tmp->next;
         n++;
       }
       return tranverse(0,n,head);

     }

     TreeNode *tranverse(int start, int end, ListNode *list) {
       int i;
       if(start>end || list==NULL)
         return NULL;
         if(start==end) {
           TreeNode *newNode = new TreeNode(list->val);
           return newNode;
         }

         ListNode *cur = list;
         int mid = start+(end-start)/2;
         for(i=start;i<mid;i++) {
           cur = cur->next;
         }
         TreeNode *newNode = new TreeNode(cur->val);
         newNode ->right = tranverse(mid+1,end,cur->next);
         newNode ->left = tranverse(0,mid-1,list);
         return newNode;
       }


     };
