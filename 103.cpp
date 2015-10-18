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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int rightFirst = false;
        std::vector<std::vector<int>> ans;
        std::vector<int> v;

        if (root == NULL)
            return ans;

        while (!(q.front() == NULL && q.size() == 1))
        {
            TreeNode *ele = q.front();
            q.pop();


            if (ele == NULL)
            {
                if (rightFirst)
                    reverse(v.begin(), v.end());
                ans.push_back(v);
                rightFirst = !rightFirst;  
                v.clear();
                q.push(NULL);
                continue;
            }
            else
            {
                v.push_back(ele->val);
                if (ele->left != NULL)
                    q.push(ele->left);
                if (ele->right != NULL)
                    q.push(ele->right);
            }
        }

        if (v.size() > 0)
        {
            if (rightFirst)
                reverse(v.begin(), v.end());
            ans.push_back(v);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    //TreeNode node4(4);
    //TreeNode node5(5);

    node1.left = &node2;
    node1.right = &node3;
    //node2.left = &node4;
    //node3.right = &node5;

    Solution s;
    std::vector<std::vector<int>> ans = s.zigzagLevelOrder(&node1);

    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    
	return 0;
}









