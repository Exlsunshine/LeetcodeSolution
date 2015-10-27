#include <iostream>
#include <vector>
#include <queue>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
    	if (root == NULL)
    		return NULL;

    	TreeNode *current = NULL;
    	if (root == p || root == q)
    		current = root;

    	TreeNode *left = lowestCommonAncestor(root->left, p, q);
    	TreeNode *right = lowestCommonAncestor(root->right, p, q);

    	if (current == root)
    		return root;
    	else
    	{
	    	if (left != NULL && right != NULL)
	    		return root;
	    	else if (left != NULL)
	    		return left;
	    	else
	    		return right;
	    }
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}