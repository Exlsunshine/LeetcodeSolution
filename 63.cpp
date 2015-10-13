#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
    	int **dp = new int*[m + 1];
    	for (int i = 0; i < m + 1; ++i)
    	{
    		dp[i] = new int[n + 1];
    		memset(dp[i], 0, sizeof(int) * (n + 1));
    	}

    	for (int i = 0; i < n + 1; i++)
    		dp[0][i] = 0;

    	for (int i = 0; i < m + 1; ++i)
    		dp[i][0] = 0;

    	dp[0][1] = 1;

    	for (int i = 1; i <= m; ++i)
    	{
    		for (int j = 1; j <= n; ++j)
    		{
    			if (obstacleGrid[i - 1][j - 1] == 1)
    				dp[i][j] = 0;
				else
	    			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    		}
    	}

    	return dp[m][n];
    }
};

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> obstacleGrid;
	std::vector<int> v = {0, 0, 0};
	std::vector<int> v2 = {0, 0, 0};
	std::vector<int> v3 = {0, 0, 0};
	obstacleGrid.push_back(v);
	obstacleGrid.push_back(v2);
	obstacleGrid.push_back(v3);
	
	Solution s;
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}









