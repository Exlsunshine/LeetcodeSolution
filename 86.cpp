#include <iostream>
#include <vector>

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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *rear = NULL;
        ListNode *front = NULL;
        ListNode *current = head;
        ListNode *newHead = head;

        while (current != NULL)
        {
            while (current != NULL && current->val < x)
            {
                front = current;
                current = current->next;
            }

            while (current != NULL && current->val >= x)
            {
                rear = current;
                current = current->next;
            }

            if (current == NULL)
                break;

            if (front != NULL)
            {
                rear->next = current->next;
                current->next = front->next;
                front->next = current;
                front = current;
                current = rear;
            }
            else
            {
                rear->next = current->next;
                current->next = head;
                front = current;
                newHead = front;
                current = rear;
            }
        }

        return newHead;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}









