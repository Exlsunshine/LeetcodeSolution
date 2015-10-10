Advanced implementation: Space O(height of the tree), Time nearly O(1)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        push_small_node(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
       	if (!q.empty())
    	{
    		TreeNode *element = q.top();
    		q.pop();
    		if (element->right != NULL)
    			push_small_node(element->right);
    		return element->val;
    	}
    }

private:
	stack<TreeNode*> q;

	void push_small_node(TreeNode *root)
	{
		TreeNode *node = root;
		while (node != NULL)
		{
			q.push(node);
			node = node->left;
		}
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */	



Naive implementation: Space O(n), Time O(1)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
    	inorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return q.empty();
    }

    /** @return the next smallest number */
    int next() {
    	int element = q.front();
    	q.pop();
        return element;
    }
private:
	queue<int> q;

	void inorder(TreeNode *root)
	{
		if (root == NULL)
			return;

		inorder(root->left);
		q.push(root->val);
		inorder(root->right);
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */