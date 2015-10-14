#include <iostream>
#include <vector>
#include <queue>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
    	int postIdx = postorder.size() - 1;
    	return build(inorder, postorder, 0, inorder.size() - 1, postIdx);
    }
private:
	TreeNode* build(const std::vector<int> &inorder, const std::vector<int> &postorder, int inLeft, int inRight, int &postIdx)
	{
		if (inLeft > inRight || inLeft < 0 || inRight >= inorder.size() || postIdx < 0)
			return NULL;

		if (inLeft == inRight)
		{
			postIdx--;
			return new TreeNode(inorder[inLeft]);
		}

		int val = postorder[postIdx];
		int index = findIndex(inorder, val);
		TreeNode *root = new TreeNode(val);
		postIdx--;
		
		root->right = build(inorder, postorder, index + 1, inRight, postIdx);
		root->left = build(inorder, postorder, inLeft, index - 1, postIdx);

		return root;
	}

	int findIndex(const std::vector<int> &v, int val)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] == val)
				return i;
		}

		return -1;
	}
};

void bfs(TreeNode *root)
{
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode *ele = q.front();
		q.pop();
		if (ele == NULL)
			cout << "NULL,";
		else
		{
			cout << ele->val << ",";
			q.push(ele->left);
			q.push(ele->right);
		}
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> inorder = {2,1,4,3,5};
	std::vector<int> postorder = {2,4,5,3,1};

	Solution s;
	bfs(s.buildTree(inorder, postorder));

	return 0;
}