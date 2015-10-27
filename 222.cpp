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
    int countNodes(TreeNode* root) 
    {
        return getCount(root);
    }

private:
	int getCount(TreeNode *root)
	{
	    if (root == NULL)
	        return 0;
	        
		TreeNode *l = root->left;
		TreeNode *r = root->right;

		int lHeight = 1;
		int rHeight = 1;
		while (l != NULL)
		{
			l = l->left;
			lHeight++;
		}

		while (r != NULL)
		{
			r = r->right;
			rHeight++;
		}

		if (lHeight == rHeight)
			return (1 << lHeight) - 1;//pow(2, lHeight) - 1;
		else
			return 1 + getCount(root->left) + getCount(root->right);
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}