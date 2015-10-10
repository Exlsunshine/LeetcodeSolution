#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
    	sort(candidates.begin(), candidates.end());
    	std::vector<std::vector<int>> ans;
    	std::vector<int> v;
    	backtracking(0, v, 0, target, candidates, ans);

    	for (int i = 0; i < ans.size(); ++i)
    	{
    		for (int j = 0; j < ans[i].size(); ++j)
    			cout << ans[i][j] << " ";
    		cout << endl;
    	}

    	return ans;
    }

private:
	void backtracking(int start, std::vector<int> &v, int total, int target, std::vector<int> &candidates, std::vector<std::vector<int>> &ans)
	{
	/*	cout << "start " << start << endl;
		cout << "total " << total << endl;
		cout << "target " << target << endl;
		cout << endl;*/

		if (total == target)
		{
			ans.push_back(v);
			return;
		}

		for (int i = start; i < candidates.size(); ++i)
		{
			if (total + candidates[i] <= target)
			{
				v.push_back(candidates[i]);
				backtracking(i, v, total + candidates[i], target, candidates, ans);
				v.pop_back();
			}
			else
				return;
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {2, 3, 6, 7};

	s.combinationSum(v, 7);
	return 0;
}