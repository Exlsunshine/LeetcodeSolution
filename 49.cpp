#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, std::vector<string>> map;

		int n = strs.size();
		for (int i = 0; i < n; ++i)
		{
			string str = strs[i];
			sort(str.begin(), str.end());

			unordered_map<string, std::vector<string>>::iterator got = map.find(str);
			if (got != map.end())
				got->second.push_back(strs[i]);
			else
				map.insert(pair<string, std::vector<string>>(str, vector<string>(1, strs[i])));
		}

		std::vector<std::vector<string>> ans;
		for (unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); it++)
			ans.push_back(it->second);
		
		for (int i = 0; i < ans.size(); i++)
			sort(ans[i].begin(), ans[i].end());

		return ans;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> v = { "eat", "tea", "tan", "ate", "nat", "bat" };
	std::vector<std::vector<string>> ans = s.groupAnagrams(v);

	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " , ";
		cout << endl;
	}

	cin.get();

	return 0;
}