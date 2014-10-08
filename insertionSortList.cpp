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
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode *cur = head;
        cur = cur->next;
        ListNode *result = new ListNode(-1);
        result->next = head;
        
        while(cur!=NULL) {
            ListNode *r = result;
            // remove cur from the list;
            while(r->next != cur)
                r = r->next;
            r->next = cur->next;
            ListNode *nextNode = cur->next;     // store the next unordered node
            // Find the proper location, where cur should be inserted after r;
            r = result;
            while(r->next != nextNode && r->next->val < cur->val)
                r = r->next;
            // Insert cur after r
            ListNode * tmp=r->next;
            r->next = cur;
            cur->next = tmp;
            
            cur = nextNode;
            
        }
        return result->next;
    }
};
