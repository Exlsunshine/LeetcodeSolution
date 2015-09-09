#include <iostream>

using namespace std;

struct ListNode
{
	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
    	if (head == NULL || head->next == NULL)
    		return head;

    	ListNode *cur = head;
    	ListNode *next = head->next;
    	ListNode *next2 = next->next;

    	cur->next = NULL;

    	while (next != NULL)
    	{
    		// reverse
    		next->next = head;

    		// update
    		head = next;
    		next = next2;

    		if (next2 == NULL)
    			break;
    		else
    			next2 = next2->next;
    	}

    	return head;
    }
};
*/

class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
    	if (head == NULL || head->next == NULL)
			return head;
		else
		{
			ListNode **new_head;
			ListNode *new_tail = reverse(head, new_head);
			new_tail->next = NULL;

			return *new_head;
		}
    }
private:
	ListNode* reverse(ListNode *node, ListNode ** head)
	{
		cout << node->val << "\t" << node << endl;

		if (node->next == NULL)
		{
			head = &node;
			return node;
		}

		ListNode *new_head = reverse(node->next, head);

		cout << "Return value is : " << new_head << endl;
		cout << "=======" << endl;
		new_head->next = node;
		return node;
	}
};

void print(ListNode *head)
{
	ListNode *p = head;
	while (p != NULL)
	{
		cout << p->val << "\t";
		p = p->next;
	}

	cout << endl;
}

int main()
{
	Solution s;

	ListNode *p = new ListNode(1);
	ListNode *q = new ListNode(2);
	p->next = q;
	print(p);

	print(s.reverseList(p));
	return 0;
}





