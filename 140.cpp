#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict)
    {
    	unordered_map<int, std::vector<string>> cache;
    	return backtracking(s, wordDict, cache, 0);
    }

private:
	std::vector<string> backtracking(string s, unordered_set<string> &wordDict, unordered_map<int, std::vector<string>> &cache, int key)
	{
		int startIndex = 0;
		std::vector<string> ans;

		if (s.length() == 0 || s == "")
			return ans;

		for (int i = 0; i < s.length(); ++i)
		{
			auto got = wordDict.find(s.substr(0, i - 0 + 1));
// 			cout << s.substr(0, i - 0 + 1) << endl;
			if (got == wordDict.end())
				continue;

			string sub = s.substr(0, i - 0 + 1);
			if (i + 1 < s.length())
			{
				std::vector<string> v;
				auto cacheVal = cache.find(key + i + 1);
				if (cacheVal == cache.end())
					v = backtracking(s.substr(i + 1), wordDict, cache, key + i + 1);
				else
					v = cacheVal->second;
				
				for (int i = 0; i < v.size(); ++i)
					ans.push_back(sub + " " + v[i]);
			}
			else
				ans.push_back(sub);
		}

		cache.insert(make_pair(key, ans));

		return ans;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}