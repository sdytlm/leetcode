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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL || head->next==NULL || k<2)
           return head;
        
        ListNode *nextGroupHead = head;         // nextGroupHead is the head of current next group
        // Move nextGroupHead to the head of current next group
        int i=0;
        while(i<k && nextGroupHead!=NULL) {
            i++;
            nextGroupHead = nextGroupHead->next;
        }
        
        if(i<k)
            return head;
        ListNode *newNextGroupHead = reverseKGroup(nextGroupHead,k);  // newNextGroupHead is the head of next group after recrusive.
       // Implement 1->2->3 ====> 1<-2<-3
		ListNode *tmpCur = head;
		ListNode *tmpPre = NULL;
		ListNode *tmpTail = tmpCur;
		while(tmpCur!=nextGroupHead) {
			ListNode *tmpNext = tmpCur->next;
			tmpCur->next = tmpPre;
			tmpPre = tmpCur;
			tmpCur = tmpNext;
		}
		// connect new group to reorganized groups
		tmpTail->next = newNextGroupHead;
		return tmpPre;
    }
};
