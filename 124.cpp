#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) 
    {
    	if (root == NULL)
    		return 0;

    	int ans = numeric_limits<int>::min();
    	dfs(root, ans);
    	return ans;
    }

private:
	int dfs(TreeNode *root, int &ans)
	{
		if (root->left == NULL && root->right == NULL)
		{
			ans = max(ans, root->val);
			return root->val;
		}

		int left = 0, right = 0;
		if (root->left != NULL)
			left = max(left, dfs(root->left, ans));
		if (root->right != NULL)
			right = max(right, dfs(root->right, ans));

		ans = max(ans, left + right + root->val);

		return max(left, right) + root->val;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}