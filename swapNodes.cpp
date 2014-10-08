/* Given a linked list, swap every two adjacent nodes and return its head.
 
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 
 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
         if(head==NULL || head->next==NULL)
            return head;
        ListNode *frontP = new ListNode(-1);
        frontP->next = head;
        ListNode *result = frontP;
        ListNode * backP = head;
        
        
        
        while(backP!=NULL && frontP!=NULL && backP->next!=NULL) {  // backP->next != NULL guarantee there will always be even number of nodes.
           ListNode *newB = frontP->next;        // store the current front pointer
           ListNode *newF = backP->next;         // store the current back pointer

           frontP->next = backP->next;
	   backP->next = backP->next->next;
	   newF->next = newB;

           frontP = newB;
           backP = newB->next;
            
        }
        return result->next;
    }
};
