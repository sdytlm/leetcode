/* A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 */

/* Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *   int label;
 *   RandomListNode *next, *random;
 *   RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 *
 */

class Solution {

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *tmp = head;

		
		// Duplicate each node of head
		// For example 1->2->3->4
		//              \  \  \  \
		//              N   4  N  N
		//                            =====>
		//                                         1->1->2->2->3->3->4->4
		//                                                \   \
	                                                first 4    second 4
	
		// Duplicates "next"
		
		while(tmp!=NULL) {
			RandomListNode *newNode = new RandomListNode(tmp->label);
			newNode->next = tmp->next;
			tmp->next = newNode;
			tmp = newNode->next;
		}

		// Duplicate "random", but the random of new node also points to the duplicated node.
		tmp = head;

		while(tmp!=NULL) {
			if(tmp->random != NULL) {
				tmp->next->random = tmp->random->next;
			}
			tmp = tmp->next->next;
		}

		// Separate the duplicated nodes from the whole list and the result is the duplicated list.

		RandomListNode *result = new RandomListNode(-1);
		RandomListNode *tmpNew = result;
		tmp = head;

		while(tmp!=NULL) {
			tmpNew->next = tmp->next;
			tmp->next = tmp->next->next;
			tmpNew = tmpNew->next;
			tmp = tmp->next;
			
		}
		return result->next;

	}

};

