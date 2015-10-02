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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *faster = head;
        ListNode *slower = head;

        while (faster != NULL && slower != NULL)
        {
        	slower = slower->next;

        	if (faster->next == NULL)
        		return NULL;
        	else
        		faster = faster->next->next;

        	if (faster == slower)
        	{
        		ListNode *begin = head;

        		while (begin != slower)
        		{
        			begin = begin->next;
        			slower = slower->next;
        		}

        		return begin;
        	}
        }

        return NULL;
    }
};