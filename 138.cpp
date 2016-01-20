#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == NULL)
            return NULL;
            
    	RandomListNode *p = head;

    	// dupicate nodes.
    	while (p != NULL)
    	{
    		RandomListNode *node = new RandomListNode(p->label);
    		RandomListNode *pNext = p->next;

    		p->next = node;
    		node->next = pNext;

    		p = pNext;
    	}

    	// build random links.
    	RandomListNode *oldNode = head;
    	RandomListNode *newNode = head->next;
    	while (oldNode != NULL && newNode != NULL)
    	{
    		newNode->random = ((oldNode->random == NULL) ? NULL : oldNode->random->next);

    		if (newNode->next == NULL)
    			break;
    		oldNode = oldNode->next->next;
    		newNode = newNode->next->next;
    	}

    	// extract new nodes.
    	RandomListNode *newHead = new RandomListNode(0);
    	oldNode = head;
    	newNode = newHead;
    	while (oldNode != NULL)
    	{
    	    // extract new nodes.
    		newNode->next = oldNode->next;
    		
    		// restore old nodes.
    		RandomListNode *pOldNext = oldNode->next->next;
    		oldNode->next = pOldNext;
    		oldNode = pOldNext;
    		newNode = newNode->next;
    	}

    	return newHead->next;
    }
};
/*
    Hashtable version.
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
    	unordered_map<RandomListNode*, int> mapOriginal;
    	unordered_map<int, RandomListNode*> mapNew;

    	// build main chain
    	RandomListNode *pOriginal = head;
    	RandomListNode *newHead = new RandomListNode(0);
    	RandomListNode *pNew = newHead;
    	int i = 1;
    	while (pOriginal != NULL)
    	{
    		pNew->next = new RandomListNode(pOriginal->label);
    		
    		mapOriginal.insert(make_pair(pOriginal, i));
    		mapNew.insert(make_pair(i, pNew->next));
    		
    		pNew = pNew->next;
    		pOriginal = pOriginal->next;
    		i++;
    	}

    	// build random link
		pOriginal = head;
		pNew = newHead->next;
		while (pOriginal != NULL)
		{
			RandomListNode *node;
			unordered_map<RandomListNode*, int>::iterator got = mapOriginal.find(pOriginal->random);
			if (got == mapOriginal.end())
				node = NULL;
			else
			{
				int idx = got->second;
				node = mapNew.find(idx)->second;
			}
			pNew->random = node;

			pOriginal = pOriginal->next;
			pNew = pNew->next;
		} 	

    	return newHead->next;
    }
};
*/

int main(int argc, char const *argv[])
{
	Solution s;
	RandomListNode *node = new RandomListNode(1);
	s.copyRandomList(node);
	return 0;
}