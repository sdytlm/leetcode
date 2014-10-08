/* Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 
 You should preserve the original relative order of the nodes in each of the two partitions.
 
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL)
            return NULL;
        ListNode *smallNode = head;  // smallNode->val < x
        ListNode *largeNode = head;  // smallNode->val >=x
        ListNode *result = new ListNode(-1);
        ListNode *tmp = result;
        // Insert lessNode into result;
        while(smallNode!=NULL) {
            if(smallNode->val<x) {
                tmp->next = new ListNode(smallNode->val);
                tmp = tmp->next;
            }
            smallNode = smallNode->next;
        }
        // Insert largeNode into result
        while(largeNode!=NULL) {
            if(largeNode->val>=x) {
                tmp->next = new ListNode(largeNode->val);
                tmp = tmp->next;
            }
            largeNode = largeNode->next;
        }
        return result->next;
    }
};