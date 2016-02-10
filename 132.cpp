#include <iostream>

using namespace std;

class Solution {
public:
    int minCut(string s)
    {
        if (s.length() <= 1)
            return 0;
        
        const int n = s.length();
        bool isPalindrome[n][n];
        memset(isPalindrome, false, n * n);

    	std::vector<int> dp(s.length());
    	for (int i = 0; i < dp.size(); ++i)
    		dp[i] = i;

    	for (int j = 0; j < s.length(); ++j)
    	{
    		for (int i = j; i >= 0; --i)
    		{
    			if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1]))
    			{
    				isPalindrome[i][j] = true;
    				dp[j] = min(dp[j], (i - 1 >= 0 ? (dp[i - 1] + 1 ) : 0));
    			}
    		}
    	}

    	return dp[s.length() - 1];
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}