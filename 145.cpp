#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
	Iterative version.
*/
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
    	stack<TreeNode*> stk;
    	std::vector<int> ans;
    	stk.push(root);

    	if (root == NULL)
    		return ans;
    	
    	while (!stk.empty())
    	{
    		TreeNode *node = stk.top();
            stk.pop();

            ans.push_back(node->val);
            if (node->left != NULL)
            	stk.push(node->left);
            if (node->right != NULL)
            	stk.push(node->right);
    	}

    	reverse(ans.begin(), ans.end());
    	return ans;
    }
};

/*
	Recursive version.
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
    	std::vector<int> ans;
    	postorder(root, ans);
    	
    	return ans;
    }

private:
	void postorder(TreeNode *root, std::vector<int> &elements)
	{
		if (root == NULL)
			return;

		postorder(root->left, elements);
		postorder(root->right, elements);
		elements.push_back(root->val);
	}
};
*/

int main(int argc, char const *argv[])
{
	Solution s;

	TreeNode *root = new TreeNode(1);
	TreeNode *r = new TreeNode(2);
	TreeNode *rl = new TreeNode(3);
	root->right = r;
	r->left = rl;

	std::vector<int> v = s.postorderTraversal(root);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\t";




	return 0;
}