#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* Space : O(N) */
class Solution {
public:
    void recoverTree(TreeNode* root)
    {
    	if (root == NULL)
    		return;

    	// get orders.
    	std::vector<int> orders;
    	inorderTraverse(root, orders);

        // find mistake nodes.
    	std::vector<int> mistakeValues;
    	for (int i = 0; i < orders.size() - 1; ++i)
    	{
    		if (orders[i] < orders[i + 1])
                continue;
                
    		mistakeValues.push_back(orders[i]);
            break;    		    
    	}
    	for (int i = orders.size() - 1; i > 0; --i)
    	{
    		if (orders[i] > orders[i - 1])
    		    continue;
    		mistakeValues.push_back(orders[i]);
            break;    		    
    	}
    	
        dfs(root, mistakeValues);
    }
private:
	void dfs(TreeNode *root, const std::vector<int> &mistakeValues)
	{
		if (root == NULL)
			return;
		
		if (root->val == mistakeValues[0])
			root->val = mistakeValues[1];
		else if (root->val == mistakeValues[1])
		    root->val = mistakeValues[0];
		
		dfs(root->left, mistakeValues);
		dfs(root->right, mistakeValues);
	}

	void inorderTraverse(TreeNode *root, std::vector<int> &orders)
	{
		if (root == NULL)
			return;

		inorderTraverse(root->left, orders);
		orders.push_back(root->val);
		inorderTraverse(root->right, orders);
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}
