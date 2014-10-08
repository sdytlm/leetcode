/* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 */

/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 */

class Solution {

public:
    ListNode *detectCycle(ListNode *head) {
		if(head==NULL || head->next==NULL)
		  return NULL;

		ListNode *slow = head;
		ListNode *fast = head;

		while(fast!=NULL) {
			slow = slow->next;
			if(fast->next==NULL)
			  return NULL;
			else
			  fast = fast->next->next;

			if(slow==fast) {	// have loop
				ListNode *slow2 = head;
				while(slow2!=slow) {
					slow2 = slow2->next;
					slow = slow->next;
				}
				return slow2;

			}
		}

		return NULL;


    }

};
