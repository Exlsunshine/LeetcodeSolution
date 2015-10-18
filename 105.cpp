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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode *build(const std::vector<int> &preorder, const std::vector<int> &inorder,
                    int pre_begin, int pre_end, int in_begin, int in_end)
    {
        if (pre_begin == pre_end || in_begin == in_end)
            return new TreeNode(preorder[pre_begin]);

        TreeNode *root = new TreeNode(preorder[pre_begin]);
        int rootIndex = findIndex(inorder, in_begin, in_end, preorder[pre_begin]);

        root->left  = build(preorder, inorder, pre_begin + 1, pre_begin + (rootIndex - in_begin), in_begin, rootIndex - 1);
        root->right = build(preorder, inorder, pre_begin + (rootIndex - in_begin) + 1, pre_end, rootIndex + 1, in_end);

        return root;
    }

    int findIndex(const std::vector<int> v, const int begin, const int end, const int key)
    {
        for (int i = begin; i <= end; ++i)
            if (v[i] == key)
                return i;

        return -1;
    }
};

int main(int argc, char const *argv[])
{   
	return 0;
}