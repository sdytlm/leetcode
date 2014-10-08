/* Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n)
            return head;
        
        ListNode *front = head;
        ListNode *rear = head;
        int i;
        for(i=1;i<m;i++)
            front = front->next;
        for(i=1;i<n;i++)
            rear = rear->next;
        
        // Add each element from m to n into n->next;
        while(front!=rear) {
            ListNode *nextP = front->next;
            front->next = rear->next;
            rear->next = front;
            front = nextP;
        }
        
        // delete the node from m to n;
        // if m=1
        if(m==1)
            head = rear;
        else {
            front = head;
            for(i=1;i<m-1;i++) // move front to the lement in m-1
                front = front->next;
            front->next = rear;
        }
        return head;
    }
};