#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
    	TreeLinkNode *nextLevelHead = NULL;
    	TreeLinkNode *currentNode = root;

    	do
    	{
    		nextLevelHead = NULL;
    		TreeLinkNode *node = currentNode;
			while (node != NULL)
			{
	    		if (node->left != NULL)
	    		{
	    			nextLevelHead = node->left;
	    			break;
	    		}
	    		else if (node->right != NULL)
	    		{
	    			nextLevelHead = node->right;
	    			break;
	    		}
	    		else
	    			node = node->next;
			}

	    	while (currentNode != NULL)
	    	{
	    		if (currentNode->left != NULL)
	    		{
	    			if (currentNode->right != NULL)
	    				currentNode->left->next = currentNode->right;
	    			else
	    			{
	    				TreeLinkNode *node = currentNode->next;
	    				TreeLinkNode *nextNotNULL = NULL;

	    				while (node != NULL)
	    				{
	    					if (node->left != NULL)
	    					{
	    						nextNotNULL = node->left;
	    						break;
	    					}
	    					else if (node->right != NULL)
	    					{
	    						nextNotNULL = node->right;
	    						break;
	    					}

	    					node = node->next;
	    				}

	    				currentNode->left->next = nextNotNULL;
					}
	    		}

	    		if (currentNode->right != NULL)
	    		{
	    			TreeLinkNode *node = currentNode->next;
					TreeLinkNode *nextNotNULL = NULL;

					while (node != NULL)
					{
						if (node->left != NULL)
						{
							nextNotNULL = node->left;
							break;
						}
						else if (node->right != NULL)
						{
							nextNotNULL = node->right;
							break;
						}

						node = node->next;
					}

					currentNode->right->next = nextNotNULL;
	    		}

	    		currentNode = currentNode->next;
	    	}

	    	currentNode = nextLevelHead;
    	} while (nextLevelHead != NULL);
    }
};

/*
	Space compexity: O(n)
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
    	queue<TreeLinkNode*> q;
    	q.push(root);
    	q.push(NULL);

		TreeLinkNode *node;
    	while (!q.empty())
    	{
    		do
    		{
    			node = q.front(); q.pop();

    			if (node == NULL)
    				return;
    			if (node->left != NULL)
    				q.push(node->left);
    			if (node->right != NULL)
    				q.push(node->right);

    			node->next = q.front();
    		} while (q.front() != NULL);

    		q.pop();
    		q.push(NULL);
    	}
    }
};
*/

int main(int argc, char const *argv[])
{
	return 0;
}