/* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
        ListNode *sortList(ListNode *head) {
        if(head== NULL || head->next==NULL)
            return head;
        ListNode *slow = head;                  // slow will point to the mid node.
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *newHead = slow->next;
        slow->next = NULL;
        
        ListNode *l1 = sortList(head);  // sort left
        ListNode *l2 = sortList(newHead);   // sort right;
        
        merge2Lists(l1,l2); // merge sorted lists;
        
    }
    // User two pointers to find the mid position.
    
    
    ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(-1);
        result->next = l1;
        ListNode *tmp = result;
        while(l1!=NULL && l2!=NULL) {
            if(l2->val < l1->val) {
                tmp->next = l2;
                l2 = l2->next;
            }
            else {
                tmp->next = l1;
                l1 = l1->next;
            }
            tmp = tmp->next;    
        }
        if(l2!=NULL)
            tmp->next = l2;
        if(l1!=NULL)
            tmp->next = l1;
        return result->next;
    }

};

