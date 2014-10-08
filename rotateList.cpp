/* Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head==NULL)
            return NULL;
        ListNode *result = new ListNode(-1);
        ListNode *tmp = result;
        ListNode *curNode = head;
        ListNode *pivotNode = head; // The first Node in new list;
        int len=0;
        int i;
        
        // Find the length of list
        while(curNode!=NULL) {
            len++;
            curNode = curNode->next;
        }
        k = k%len;
        
        // Find the pivot node
        for(i=0;i<len-k;i++) {
            pivotNode = pivotNode->next;
        }
        curNode = pivotNode;
        
        // Put node into new list from pivot to the last node;
        while(curNode!=NULL) {
            tmp->next = new ListNode(curNode->val);
            tmp = tmp->next;
            curNode = curNode->next;
        }
        
        // Put node into new list from old head to pivot
        curNode = head;
        while(curNode != pivotNode) {
            tmp->next = new ListNode(curNode->val);
            tmp = tmp->next;
            curNode = curNode->next;
        }
        return result->next;
    }
};