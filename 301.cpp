#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s)
    {
    	std::vector<string> ans;
    	int minLevel = INT_MAX;
    	unordered_set<string> set;
        
        if (isValid(s))
            ans.push_back(s);
        else
        	ans = dfs(s, 1, minLevel, set);

        /*
    	for (int i = 0; i < ans.size(); ++i)
    	{
    		cout << ans[i] << endl;
    	}
    	*/
    	return ans;
    }

private:
	std::vector<string> dfs(string str, int level, int &minLevel, unordered_set<string> &set)
	{
		std::vector<string> ans, child;
		if (level > minLevel)
			return ans;
			
        bool allChars = true;
		bool stop = false;

		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] != '(' && str[i] != ')')
				continue;
				
			allChars = false;

			string temp = str;
			temp.erase(i, 1);

            // dupicate
			if (set.find(temp) != set.end())
				continue;
			else
				set.insert(temp);

			if (isValid(temp))
			{
				ans.push_back(temp);
				stop = true;
				minLevel = min(minLevel, level);
			}
			else if (!stop)
			{
				int inLevel = minLevel;
				std::vector<string> v = dfs(temp, level + 1, minLevel, set);
				int ouLevel = minLevel;

				if (ouLevel < inLevel)
				{
					child = v;
				}
				else if (ouLevel == inLevel && v.size() > 0)
				{
					child.insert(child.end(), v.begin(), v.end());
				}
			}
		}
        
		if (stop)
			return ans;
		else
		{
		    if (allChars)
                child.push_back(str);
			return child;
		}
	}

	bool isValid(string str)
	{
		int leftCnt = 0;

		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == '(')
				leftCnt++;
			else if (str[i] == ')')
				leftCnt--;

			if (leftCnt < 0)
				return false;
		}

		return leftCnt == 0;
	}
};


int main(int argc, char const *argv[])
{
	Solution s;
	s.removeInvalidParentheses("((()((s((((()");
	return 0;
}