#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


void printNodes(ListNode *head)
{
	ListNode *p = head;

	cout << endl;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
    	// validation check.
    	if (head == NULL || k == 0)
    		return head;

    	// find the range to be reversed,
    	// or return if the number of the left nodes < k.
    	int cnt = 1;
    	ListNode *tail = head;
    	while (cnt < k && tail != NULL)
    	{
    		tail = tail->next;
    		cnt++;
    	}
    	if (tail == NULL)
    		return head;

    	// reverse from head to tail.
    	ListNode *nextHead = tail->next;
    	tail->next = NULL;
    	reverseList(head, tail);

    	ListNode *newNextHead = reverseKGroup(nextHead, k);

    	tail->next = newNextHead;
    	return head;
    }

private:
	void reverseList(ListNode *&head, ListNode *&tail)
	{
		if (head == NULL || head->next == NULL)
			return;

		ListNode *pCurrent = head;
		ListNode *pNext = head->next;

		pCurrent->next = NULL;
		while (true)
		{
			ListNode *p = pNext->next;
			pNext->next = pCurrent;
			pCurrent = pNext;

			if (p == NULL)
				break;
			else
				pNext = p;
		}

		tail = head;
		head = pNext;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	printNodes(node1);
	ListNode *head = s.reverseKGroup(node1, 3);
	printNodes(head);

	return 0;
}