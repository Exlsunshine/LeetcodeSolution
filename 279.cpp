#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n)
    {
    	int max_prob = (int)sqrt(n);
    	int **dp = new int*[max_prob + 1];
    	for (int i = 0; i < max_prob + 1; ++i)
    	{
    		dp[i] = new int[n + 1];
    		memset(dp[i], 0, sizeof(int) * (n + 1) );
    	}

    	for (int i = 1; i <= n; ++i)
    		dp[1][i] = i;

    	for (int i = 2; i <= max_prob; ++i)
    	{
    		for (int k = 1; k <= n; ++k)
    		{
    			if (k >= i * i)
    				dp[i][k] = min(dp[i][k - i * i] + 1, dp[i - 1][k]);
    			else
    				dp[i][k] = dp[i - 1][k];
    		}
    	}

    	return dp[max_prob][n];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.numSquares(13) << endl;
	return 0;
}