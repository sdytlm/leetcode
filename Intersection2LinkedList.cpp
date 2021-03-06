/* Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL)
      return NULL;
    // 统计两个链表的长度
    int lenA = listLength(headA);
    int lenB = listLength(headB);
    // 按照最短的链表对齐
    while(lenA > lenB) {
      headA = headA->next;
      lenA--;
    }
    while(lenB > lenA) {
      headB = headB->next;
      lenB--;
    }
    // 两个链表分别从新的起点，找第一个相同的node就是intersection

    while(headA!=NULL) {
      if(headA == headB) // 找到intersection
        return headA;
      headA = headA->next;
      headB = headB->next;
    }
    return NULL;
  }

  int listLength(ListNode *list) {
    int result = 0;
    while(list!=NULL) {
      result++;
      list = list->next;
    }
    return result;
  }
};
