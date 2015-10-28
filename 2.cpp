#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    	ListNode *newHead = new ListNode(0);
    	ListNode *head = newHead;
    	int carryIn = 0;
    	
    	while (l1 != NULL && l2 != NULL)
    	{
    		int sum = l1->val + l2->val + carryIn;
    		head->next = new ListNode(sum % 10);
    		carryIn = sum / 10;
    		head = head->next;

    		l1 = l1->next;
    		l2 = l2->next;
    	}

    	while (l1 != NULL)
    	{
    		int sum = l1->val + carryIn;
    		head->next = new ListNode(sum % 10);
    		carryIn = sum / 10;
    		head = head->next;

    		l1 = l1->next;
    	}

    	while (l2 != NULL)
    	{
    		int sum = l2->val + carryIn;
    		head->next = new ListNode(sum % 10);
    		carryIn = sum / 10;
    		head = head->next;

    		l2 = l2->next;
    	}

    	return newHead.next;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}