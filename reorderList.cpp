/* Given a singly linked list L: l0->l1-> ... ln-1->ln;
   reorder it to: l0->ln->l1->ln-1->l2->ln-2...
   You must do this in-place without altering the nodes' values.
   For example,
   Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/* Definition for singly-linked list.
 * struct ListNode {
 *    int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */

class Solution {
public:
   void reorderList(ListNode *head) {
			if(head==NULL || head->next==NULL)
			  return ;
			
			int len=0;
			ListNode *tmp = head;
			while(tmp!=NULL) {
				tmp = tmp->next;
				len++;
			}
			if(len<=2)
			  return ;

			int halfLen = len%2==0?len/2:len/2+1;
			int i;
			ListNode *halfList;		// The head of second half list;
			tmp = head;
			for(i=0;i<halfLen-1;i++)
			  tmp = tmp->next;
			halfList = tmp->next;  // Break the list
			tmp->next = NULL;
			ListNode *newHalfList = reverse(halfList); // reverse the second half list;
			tmp = head;
			while(tmp!=NULL && newHalfList!=NULL) {
				ListNode *nextNode = tmp->next;             // next node in first half
				ListNode *nextNode2 = newHalfList->next;    // next node in second half
				tmp->next = newHalfList;                    // connect first half and second half as required     
				newHalfList->next = nextNode;
				tmp = nextNode;
				newHalfList = nextNode2;
				
			}
			return ;
			

        }

		ListNode *reverse(ListNode *head) {
			ListNode *dummy = new ListNode(-1);
			dummy->next = head;
			ListNode *prev = dummy;
			ListNode *cur = head;
			
			while(cur!=NULL) {
				ListNode *next = cur->next;             // change 1->2->3->4 to 1<-2<-3<-4 and return 4's pointer
				cur->next = prev;
				prev = cur;
				cur = next;
			}
			head->next = NULL;
			return prev;
			

		}
};
