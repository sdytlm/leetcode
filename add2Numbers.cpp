/* You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */

/**
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *    int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int addon=0;
        ListNode *result = new ListNode(-1);
        ListNode *head = result;
        if(l1==NULL && l2==NULL)
             return NULL;
        // Both l1 and l2 has at least 1 digit.
        while(l1!=NULL && l2!=NULL) {
            int sum = l1->val+l2->val+addon;
            if(sum>=10) {
                addon=1;
                head->next = new ListNode(sum-10);
            }
            else {
                addon=0;
                head->next = new ListNode(sum);
            }
            l1=l1->next;
            l2=l2->next;
            head=head->next;
        }
        
        // l1 has digit left
        while(l1!=NULL) {
            int sum = l1->val+addon;
            if(sum>=10) {
                addon=1;
                head->next = new ListNode(sum-10);
            }
            else {
                addon=0;
                head->next = new ListNode(sum);
            }
            l1=l1->next;
            head=head->next;
        }
        // l2 has digit left
        while(l2!=NULL) {
            int sum = l2->val+addon;
            if(sum>=10) {
                addon=1;
                head->next = new ListNode(sum-10);
            }
            else {
                addon=0;
                head->next = new ListNode(sum);
            }
            l2=l2->next;
            head=head->next;

        }
        // Has addon for the highest digit
        if(addon==1)
            head->next = new ListNode(1);
        return result->next;
    }

};
