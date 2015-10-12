#include <iostream>
#include <vector>

using namespace std;

void backTracking(int level, int n, std::vector<int> &v, std::vector<std::vector<int>> &ans, std::vector<int> arr)
{
	if (level == n)
		return;

	for (int i = level; i < n; ++i)
	{
		if (i - 1 >= 0 && arr[i] == arr[i - 1] && i > level)
				continue;
		v.push_back(arr[i]);
		ans.push_back(v);

		backTracking(i + 1, n, v, ans, arr);

		v.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	std::vector<std::vector<int>> ans;
	std::vector<int> arr = {1,2,2};

	ans.push_back(v);
	backTracking(0, arr.size(), v, ans, arr);

	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}