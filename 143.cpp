#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


void printList(ListNode *h)
{
  ListNode *head = h;
  while (head != NULL)
  {
    cout << head->val;
    head = head->next;
  } 

  cout << endl;
}


class Solution {
public:
  void reorderList(ListNode* head)
  {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
      return;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL)
    {
      fast = fast->next;

      if (fast != NULL)
        fast = fast->next;
      else
      {
        ListNode *temp = slow->next;
        slow->next = NULL;
        slow = temp;
        break;
      }

      if (fast == NULL)
      {
        ListNode *temp = slow->next;
        slow->next = NULL;
        slow = temp;
        break;
      }

      slow = slow->next;
    }

    ListNode *left = head;
    ListNode *right = reverseList(slow);

    ListNode *p = new ListNode(0);
    ListNode *newHead = p;
    while (left != NULL || right != NULL)
    {
      p->next = left;
      left = left->next;
      p = p->next;
      p->next = right;
      p = p->next;
      if (right != NULL)
        right = right->next;
    }

    head = newHead->next;
  }
private:
	ListNode* reverseList(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *front = head->next;
		ListNode *back = head;

    back->next = NULL;
    while (front != NULL)
    {
     ListNode *nextNeighbour = front->next;
     front->next = back;

     back = front;
     front = nextNeighbour;
   }

   return back;
 }
};

int main(int argc, char const *argv[])
{
  Solution s;
  
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  ListNode n6(6);
  ListNode n7(7);
  ListNode n8(8);

  n1.next = &n2;
  n2.next = &n3;
  /*
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;
  n6.next = &n7;
  n7.next = &n8;
  */

  ListNode *head = &n1;
  s.reorderList(head);



  while (head != NULL)
  {
    cout << head->val;
    head = head->next;
  }


  return 0;
}