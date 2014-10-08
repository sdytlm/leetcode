/* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*  超时
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        	if(lists.empty()) return NULL;
        	int i;
			ListNode *tmp = lists[0];

			for(i=1;i<lists.size();i++) {
				tmp = merge2Lists(tmp,lists[i]);
			}
			return tmp;

	    }

		ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
			ListNode *dummy = new ListNode(pow(-2,31));
			ListNode *tmp = dummy;

			while(l1!=NULL && l2!=NULL) {
				if(l1->val < l2->val) {
					tmp->next = l1;
				    l1 = l1->next;
				}
				else {
					tmp->next = l2;
					l2 = l2->next;
				}
				tmp = tmp->next;
			
			}

			if(l1==NULL)
			  tmp->next = l2;
			if(l2==NULL)
			  tmp->next = l1;
		
			return dummy->next;
		}
};

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


/*struct Comp {
	bool operator() (const ListNode* n1, const ListNode* n2) const{
		return (n1->val > n2->val);
	}

};
*/

bool Comp(ListNode *n1, ListNode *n2) {
	return n1->val > n2->val;
}
class Solution {
public:
	
	
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.empty())
		  return NULL;
		vector<ListNode *> heap;
		ListNode *result = new ListNode(-1);
		ListNode *tmp = result;
		int i;
		
		// 把所有链表的第一个放进heap中
		for(i=0;i<lists.size();i++) {
			if(lists[i]!=NULL)
			    heap.push_back(lists[i]);
		}
		
		// 建堆
		make_heap(heap.begin(),heap.end(),Comp);
		

		while(!heap.empty()) {
			
			
			pop_heap(heap.begin(),heap.end(), Comp);	// 删除最小的节点
			
			ListNode *minNode = heap.back();
			
			tmp->next = minNode;
			
			heap.pop_back();
			

			if(minNode->next!=NULL) {
				heap.push_back(minNode->next);	            // 把删除节点后续节点插入
				
				push_heap (heap.begin(), heap.end(), Comp); 
			}	

			tmp = tmp->next;
		
		}
		return result->next;


	
	}

};

int main()
{
	Solution sol;
	vector <ListNode*> lists;
	ListNode *tmp = new ListNode(0);
	ListNode *tmp1 = new ListNode(1);
	lists.push_back(tmp);
	lists.push_back(tmp1);
//	sol.mergeKLists(lists);
	cout << lists.back()->val << endl;
	make_heap(lists.begin(),lists.end(),Comp);
	
	pop_heap(lists.begin(),lists.end(),Comp);
	cout << lists.back()->val << endl;
	lists.pop_back();


	lists.push_back(new ListNode(2));
	push_heap(lists.begin(),lists.end(),Comp);
	cout << lists.back()->val << endl;

}
