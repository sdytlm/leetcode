class Solution {
	public:
		    ListNode *deleteDuplicates(ListNode *head) 
			{

				if((head==NULL) || (head->next==NULL))
				  return head;
				ListNode *curP = head;
				while(curP!=NULL)
				{
					// Find different node.
					ListNode *nextP = curP->next;
					while((nextP != NULL) && (curP->val==nextP->val))
						nextP = nextP->next;
					curP->next = nextP;
					curP = curP->next;
				}
				
				
				return head;
		    }

};
