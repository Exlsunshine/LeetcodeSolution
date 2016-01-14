#include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t)
    {
    	int col = s.length();
    	int row = t.length();
    	int **dp = new int*[row + 1];
    	for (int i = 0; i < row + 1; ++i)
    	{
    		dp[i] = new int[col + 1];
    		memset(dp[i], 0, sizeof(int) * (col + 1));
    	}

    	dp[1][1] = (t[0] == s[0] ? 1 : 0);
    	for (int i = 2; i <= col; ++i)
    	{
    		dp[1][i] = dp[1][i - 1] + (t[0] == s[i - 1] ? 1 : 0);
    	}
    	
    	for (int i = 2; i <= row; ++i)
    	{
    		for (int j = i; j <= col; ++j)
    		{
    			if (t[i - 1] == s[j - 1])
    				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
    			else
    				dp[i][j] = dp[i][j - 1];
    		}
    	}

    	return dp[row][col];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << endl << s.numDistinct("rabibiab", "raia");
	return 0;
}