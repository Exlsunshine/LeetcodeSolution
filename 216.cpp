#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
    	std::vector<int> element;
    	std::vector<std::vector<int>> ans;
    	backtracking(1, element, ans, 0, n, k);

/*
    	for (int i = 0; i < ans.size(); ++i)
    	{
    		for (int j = 0; j < ans[i].size(); ++j)
    			cout << ans[i][j] << " ";
    		cout << endl;
    	}
*/
    	return ans;
    }
private:
	void backtracking(int level, std::vector<int> &element, std::vector<std::vector<int>> &ans, int val, int n, int k)
	{
		if (val > n || (k == 0 && val != n) || (k > 0 && val == n))
			return;
		else if (val == n)
		{
			ans.push_back(element);
			return;
		}

		for (int i = level; i <= n - val && i <= 9; ++i)
		{
			element.push_back(i);
			backtracking(i + 1, element, ans, val + i, n, k - 1);
			element.pop_back();
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;

	s.combinationSum3(2, 9);
	return 0;
}