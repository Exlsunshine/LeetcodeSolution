#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		if (s1.length() + s2.length() != s3.length())
			return false;

		std::vector< std::vector<bool> > dp(s1.length() + 1, std::vector<bool>(s2.length() + 1, false));

		for (int i = 0; i <= s1.length(); ++i)
		{
			for (int j = 0; j <= s2.length(); ++j)
			{
				if (i == 0 && j == 0)
					dp[i][j] = true;
				else if (i == 0)
					dp[i][j] = dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
				else if (j == 0)
					dp[i][j] = dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
				else
					dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}

		return dp[s1.length()][s2.length()];
	}
};

/*	Backtracking
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		if (s1.length() + s2.length() != s3.length())
			return false;

		unordered_set<int> set;
		return helper(s1, s2, s3, 0, 0, 0, set);
	}

private:
	bool helper(string s1, string s2, string s3, int i, int j, int k, unordered_set<int> &set)
	{
		if (set.find(i * s3.length() + j) != set.end())
			return false;

		if (s3.length() == k)
			return true;

		bool result = false;
		if (i < s1.length() && s1[i] == s3[k])
			result |= helper(s1, s2, s3, i + 1, j, k + 1, set);
		if (j < s2.length() && s2[j] == s3[k] && !result)
			result |= helper(s1, s2, s3, i, j + 1, k + 1, set);

		set.insert(i * s3.length() + j);

		return result;
	}
};
*/

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc");

	return 0;
}