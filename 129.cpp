/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
    	int sum = 0;
    	dfs(root, 0, sum);
    	return sum;
    }

private:
	void dfs(TreeNode *root, int val, int &sum)
	{
		if (root != NULL)
		{
			if (root->left == NULL && root->right == NULL)
				sum += val * 10 + root->val;
			else 
			{
			    if (root->left != NULL)
				    dfs(root->left, val * 10 + root->val, sum);
			    if (root->right != NULL)
				    dfs(root->right, val * 10 + root->val, sum);
			}
		}
	}
};