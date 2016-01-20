#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
    Segment Tree version.
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
    	std::vector<int> ans(nums.size(), 0);
    	if (nums.size() == 0)
    	    return ans;

    	int maxVal = numeric_limits<int>::min();
    	int minVal = numeric_limits<int>::max();
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		maxVal = max(maxVal, nums[i]);
    		minVal = min(minVal, nums[i]);
    	}

		sgmTree = new SegmentTreeNode[4 * (maxVal - minVal + 1)];
		buildSegmentTree(1, minVal, maxVal);

		for (int i = nums.size() - 1; i >= 0; --i)
			ans[i] = insert(1, nums[i]);

    	return ans;
    }

private:
	class SegmentTreeNode
	{
	public:
		int left, right;
		int value; // number of x, where  left <= x < right.
		int rightBoundaryCnt;// number of x where x == right.
		int delayMarkCnt;

		SegmentTreeNode() { left = right = value = delayMarkCnt = rightBoundaryCnt = 0; }
	};

	SegmentTreeNode *sgmTree;

	void buildSegmentTree(int root, int from, int to)
	{
	    // deal with the situation like: [form,to] is [-3, -2] or [-1, 0]
	    if (from < 0 && (to - from) == 1)
	    {
	        sgmTree[root].left = from;
	        sgmTree[root].right = to;
	        sgmTree[root * 2].left = sgmTree[root * 2].right = from;
	        sgmTree[root * 2 + 1].left = sgmTree[root * 2 + 1].right = to;
	        return;
	    }
		
		if (from == to)
		{
			sgmTree[root].left = sgmTree[root].right = from;
			return;
		}

		int mid = (from + to) / 2;
		// left child
		buildSegmentTree(root * 2, from, mid);
		// right child
		buildSegmentTree(root * 2 + 1, mid + 1, to);
		sgmTree[root].left = from;
		sgmTree[root].right = to;
	}

	int insert(int root, int value)
	{
		if (sgmTree[root].right == value)
		{
			sgmTree[root].rightBoundaryCnt++;
			return sgmTree[root].value;
		}

		int mid = (sgmTree[root].left + sgmTree[root].right) / 2;
		if (value <= mid)
		{
			int cnt = insert(root * 2, value);
			//	  [left, right) = [left, mid) + [mid, mid] + [mid, right);
			sgmTree[root].value = (sgmTree[root * 2].value + sgmTree[root * 2].rightBoundaryCnt) + (sgmTree[root * 2 + 1].value);
			return cnt;
		}
		else
		{
			int cnt = insert(root * 2 + 1, value);

			sgmTree[root].value = (sgmTree[root * 2].value + sgmTree[root * 2].rightBoundaryCnt) + (sgmTree[root * 2 + 1].value);
			return sgmTree[root * 2].value + sgmTree[root * 2].rightBoundaryCnt + cnt;
		}
	}
};

/*
    Binary Search Tree version.
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
    	std::vector<int> ans(nums.size(), 0);
    	Node *root = NULL;

    	for (int i = nums.size() - 1; i >= 0; --i)
    	{
    		int cnt = 0;
    		root = addNode(nums[i], root, cnt);
    		ans[i] = cnt;
    	}

    	return ans;
    }

private:
	class Node
	{
	public:
		int val;
		int leftCnt, rightCnt, equalCnt;
		Node *left, *right;

		Node(int val)
		{
			this->val = val;
			leftCnt = rightCnt = 0;
			left = right = NULL;
			equalCnt = 1;
		}
	};

	Node *addNode(int val, Node *root, int &ans)
	{
		if (root == NULL)
			return (new Node(val));

		if (val == root->val)
		{
			root->equalCnt++;
			ans += root->leftCnt;
			return root;
		}
		else if (val > root->val)
		{
			root->rightCnt++;
			ans += root->leftCnt + root->equalCnt;
			root->right = addNode(val, root->right, ans);
			return root;
		}
		else
		{
			root->leftCnt++;
			root->left = addNode(val, root->left, ans);
			return root;
		}
	}
};*/

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {5, 2, 6, 1};
	s.countSmaller(v);

	return 0;
}