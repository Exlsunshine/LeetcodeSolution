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
    ListNode* sortList(ListNode* head)
    {
        int cnt = 0;
        ListNode *p = head;
        while (p != NULL)
        {
            cnt++;
            p = p->next;
        }

        return mergeSort(head, cnt);
    }

private:
    ListNode *mergeSort(ListNode *head, int count)
    {
        if (head == NULL)
            return head;
        if (count == 1)
        {
            head->next = NULL;
            return head;
        }

        ListNode *part1 = head;
        ListNode *part2 = head;
        for (int i = 0; i < count / 2; ++i)
            part2 = part2->next;

        ListNode *ans1 = mergeSort(part1, count / 2);
        ListNode *ans2 = mergeSort(part2, count - count / 2);
        ListNode *newHead = new ListNode(0);
        ListNode *p = newHead;

        while (ans1 != NULL && ans2 != NULL)
        {
            if (ans1->val <= ans2->val)
            {
                p->next = ans1;
                p = p->next;
                ans1 = ans1->next;
            }
            else
            {
                p->next = ans2;
                p = p->next;
                ans2 = ans2->next;
            }
        }
        
        if (ans1 != NULL)
            p->next = ans1;
        if (ans2 != NULL)
            p->next = ans2;

        return newHead->next;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}