#include <iostream>
#include <vector>

using namespace std;

/*		Space O(N)		*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
    	std::vector<int> dp(triangle.size() + 1, INT_MAX);
    	dp[1] = 0;

    	for (int i = 1; i <= triangle.size(); ++i)
    	{
    		int lastVal = dp[0];
    		for (int j = 1; j <= i; ++j)
    		{
    			int temp = min(dp[j - 1], dp[j]) + triangle[i - 1][j - 1];
    			dp[j - 1] = lastVal;
    			lastVal = temp;
	  		}
    		dp[i] = lastVal;
    	}

    	int minVal = INT_MAX;
    	for (int i = 1; i <= triangle.size(); ++i)
    	{
    		if (dp[i] < minVal)
    			minVal = dp[i];
    	}

    	return minVal;
    }
};


/*
 *		Space O(N*N)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
    	std::vector<std::vector<int>> dp(triangle.size() + 1, std::vector<int>(triangle.size() + 1, INT_MAX));
    	dp[0][0] = 0;
    	for (int i = 1; i <= triangle.size(); ++i)
    	{
    		for (int j = 1; j <= i; ++j)
    		{
    			dp[i][j] = min(dp[i- 1][j], dp[i - 1][j - 1]) + triangle[i - 1][j - 1];
    		}
    	}

    	int minVal = INT_MAX;
    	for (int i = 1; i <= triangle.size(); ++i)
    	{
    		if (dp[triangle.size()][i] < minVal)
    			minVal = dp[triangle.size()][i];
    	}

    	return minVal;
    }
};
*/
int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> triangle;
	std::vector<int> v = {2};
	triangle.push_back(v);
	v = {3,4};
	triangle.push_back(v);
	v = {6,5,7};
	triangle.push_back(v);
	v = {4,1,8,3};
	triangle.push_back(v);

	Solution s;
	cout << s.minimumTotal(triangle) << endl;
	return 0;
}