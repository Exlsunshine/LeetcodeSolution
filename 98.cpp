#include <iostream>
#include <vector>

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
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
    	return checkValidation(root);
    }
private:
	bool checkValidation(int min, int max, TreeNode *root)
	{
		if (root == NULL)
			return true;

		bool valid = true;
		if (root->left->val > root->val)
			valid = false;
		if (root->right->val < root->val)
			valid = false;

		if (root->left->val <= min)
			valid = false;
		if (root->right->val >= max)
			valid = false;

		if (valid)
			return checkValidation(min, root->val, root->left) && checkValidation(root->val, max, root->right);
		else
			return false;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}