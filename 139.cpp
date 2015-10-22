#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        int length = s.length();
        std::vector<bool> dp(length + 1, false);
        dp[0] = true;

        for (int i = 1; i <= length; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                if (dp[j - 1] && wordDict.find(s.substr(j - 1, i - j + 1)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[length];
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    unordered_set<string> wordDict;
    wordDict.insert("leet");
    wordDict.insert("code");
    cout << s.wordBreak("leetcode", wordDict);

	return 0;
}