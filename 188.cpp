#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
    	int len = prices.size();

    	if (k >= len / 2)
    	{
    		int profit = 0;
    		for (int i = 1; i < prices.size(); ++i)
    		{
    			if (prices[i] > prices[i - 1])
    				profit += prices[i] - prices[i - 1];
    		}

    		return profit;
    	}

    	std::vector< std::vector<int> > dp(k + 1, std::vector<int>(len + 1, 0));
    	for (int i = 1; i <= k; ++i)
    	{
    		int currentMax = -prices[0];
    		for (int j = 1; j <= len; ++j)
    		{
    			dp[i][j] = max(dp[i][j - 1], prices[j - 1] + currentMax);
    			currentMax = max(currentMax, dp[i - 1][j - 1] - prices[j - 1]);
    		}
    	}

    	return dp[k][len];
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}