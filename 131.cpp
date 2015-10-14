#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) 
    {
    	std::vector< std::vector<string> > ans;
    	std::vector<string> v;
    	backTracking(0, ans, s, v);

    	for (int i = 0; i < ans.size(); ++i)
    	{
    		for (int j = 0; j < ans[i].size(); ++j)
	    		cout << ans[i][j] << ",";
    		cout << endl;
    	}
    	return ans;
    }
private:
	bool isPalindrome(const string &str, const int start, const int end)
	{
		int i = start, j = end;

		while (str[i] == str[j] && i < j)
		{
			i++;
			j--;
		}

		if (i >= j)
			return true;
		else
			return false;
	}

	void backTracking(int start, std::vector< std::vector<string> > &ans, const string &str, std::vector<string> &v)
	{
		if (start >= str.length())
			return;

		for (int i = start; i < str.length(); ++i)
		{
			if (isPalindrome(str, start, i))
			{
				v.push_back(str.substr(start, i - start + 1));
				if (i == str.length() - 1)
				{
					ans.push_back(v);
					v.pop_back();
					return;
				}
				backTracking(i + 1, ans, str, v);
				v.pop_back();
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	s.partition("aaa");
	return 0;
}