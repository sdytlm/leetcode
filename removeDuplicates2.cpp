class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
       if((head==NULL) || (head->next==NULL))
		 return head;
	   ListNode *dummy = new ListNode(-2^31);
        dummy->next = head;
	   head = dummy;
	   while((head->next!=NULL) && (head->next->next!=NULL))
	   {
           if(head->next->val == head->next->next->val) // Find duplicates
           {
               int value = head->next->val;
               while((head->next!=NULL) && head->next->val == value)
               {
                   head->next = head->next->next;
               }
               // Notes: you dont need to move head if you find duplicates.
           }
           else // No duplicates
               head = head->next;
       }
        return dummy->next;

    }
};
