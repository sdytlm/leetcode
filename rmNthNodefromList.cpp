/* Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *result = new ListNode(-1);
        result->next = head;
        ListNode *frontP = result;
        ListNode *rearP = result;
        int i;
        
        // Let rearP move n step
        for(i=0;i<n;i++)
            rearP = rearP->next;
        
        // Move both pointer until rearP reach the end of list
        while(rearP->next != NULL) {
            frontP = frontP->next;
            rearP = rearP->next;
        }
        // Right now frontP->next is the one you want to remove
        
        frontP->next = frontP->next->next;
        return result->next;
    }
};