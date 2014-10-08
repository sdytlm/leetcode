/* Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 *
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 */

class Solution {

public:
    bool hasCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		if(head==NULL || head->next==NULL)
		  return false;
		while(fast!=NULL) {
			slow = slow->next;                   // slow move 1 step
			if(fast->next!=NULL)
			  fast = fast->next->next;           // fast move 2 steps
			else
			  return false;
			if(slow==fast)                       // If fast catach up slow, then exists loop
			  return true;
		}
		return false;

	}

};
