#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        if (root == NULL)
            return;
            
    	flat(root);

    	while (root != NULL)
    	{
    		cout << root->val;
    		root = root->right;
    	}
    }

private:
	TreeNode* flat(TreeNode *root)
	{
		if (root->left == NULL && root->right == NULL)
			return root;

		if (root->left != NULL && root->right != NULL)
		{
			TreeNode *l = flat(root->left);
			TreeNode *r = flat(root->right);

			l->right = root->right;
			root->right = root->left;
			root->left = NULL;
			return r;
		}
		if (root->left == NULL)
			return flat(root->right);
		else
		{
			TreeNode *l = flat(root->left);
			root->right = root->left;
			root->left = NULL;
			return l;
		}
	}
};


int main(int argc, char const *argv[])
{
	Solution s;
	TreeNode root(0), left(1) , right(2);
	root.left = &left;
	root.right = &right;
	s.flatten(&root);
	return 0;
}