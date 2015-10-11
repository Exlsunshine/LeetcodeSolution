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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        std::vector<int> v;
        dfs(0, v, root);

        for (int i = 0; i < v.size(); ++i)
            cout << v[i] << " ";
        return v;
    }

private:
    void dfs(int i, std::vector<int> &v, TreeNode *root)
    {
        if (root == NULL)
            return;

        if (i >= v.size())
            v.push_back(root->val);
        else
            v[i] = root->val;

        dfs(i + 1, v, root->left);
        dfs(i + 1, v, root->right);
    }
};

int main()
{
    Solution s;
    TreeNode root(1);
    s.rightSideView(&root);
    return 0;
}
