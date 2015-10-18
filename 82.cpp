#include <iostream>

using namespace std;

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
    ListNode* deleteDuplicates(ListNode* head)
    {
    	ListNode *current = head;
    	ListNode *previous = NULL;

    	while (current != NULL)
    	{
    		if (current->next != NULL)
    		{
    			if(current->val == current->next->val)
    			{
    				ListNode *p = current;
    				while (p != NULL && p->val == current->val)
    					p = p->next;

    				if (previous == NULL)
    					head = p;
    				else
    					previous->next = p;

   					current = p;
    			}
    			else
    			{
    				previous = current;
    				current = current->next;
    			}
    		}
    		else
    			break;
    	}

    	return head;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}