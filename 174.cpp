#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector< vector<int> >& dungeon)
    {
    	const int m = dungeon.size();
    	const int n = dungeon[0].size();

    	int dp[m + 1][n + 1];
    	for (int i = 0; i <= m; ++i)
    		dp[i][n] = numeric_limits<int>::max();
    	
    	for (int i = 0; i <= n; ++i)
    		dp[m][i] = numeric_limits<int>::max();
    		
    	dp[m][n - 1] = 1;
    	dp[m - 1][n] = 1;

    	for (int i = m - 1; i >= 0; --i)
    	{
    		for (int j = n - 1; j >= 0; --j)
    		{
    			int minNeed = min(dp[i + 1][j], dp[i][j + 1]);

    			if (dungeon[i][j] == 0)
    				dp[i][j] = minNeed;
    			else if (dungeon[i][j] < 0)
    				dp[i][j] = -1 * dungeon[i][j] + minNeed;
    			else
    			{
    				if (dungeon[i][j] - minNeed >= 0)
    					dp[i][j] = 1;
    				else
    					dp[i][j] = minNeed - dungeon[i][j];
    			}
    		}
    	}

    	return dp[0][0];
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}