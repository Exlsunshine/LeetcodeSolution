#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
    	if (lists.size() == 0)
    		return NULL;

    	return devideConquer(lists, 0, lists.size() - 1);
    }

private:
	ListNode* devideConquer(const std::vector<ListNode*> &lists, int i, int j)
	{
		if (i == j)
			return lists[i];

		int m = (i + j)/ 2;
		ListNode *left = devideConquer(lists, i, m);
		ListNode *right = devideConquer(lists, m + 1, j);

		ListNode *head = new ListNode(0);
		ListNode *p = head;
		while (left != NULL && right != NULL)
		{
			if (left->val <= right->val)
			{
				p->next = left;
				left = left->next;
			}
			else
			{
				p->next = right;
				right = right->next;
			}

			p = p->next;
		}
		while (left != NULL)
		{
			p->next = left;
			left = left->next;
			p = p->next;
		}
		while (right != NULL)
		{
			p->next = right;
			right = right->next;
			p = p->next;
		}

		return head->next;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}