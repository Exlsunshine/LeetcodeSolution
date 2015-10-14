#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        
    	int ***dp = new int**[nums.size() + 1];
    	for (int i = 0; i < nums.size() + 1; ++i)
    		dp[i] = new int*[2];

    	for (int i = 0; i < nums.size() + 1; ++i)
    	{
    		for (int j = 0; j < 2; ++j)
	    	{
	    		dp[i][j] = new int[2];
	    		memset(dp[i][j], 0, sizeof(int) * 2);
			}
		}

		dp[1][1][0] = nums[0];
		dp[1][1][1] = nums[0];
		dp[2][1][0] = nums[0];
		dp[2][1][0] = nums[0];
		for (int i = 3; i < nums.size(); ++i)
		{
			dp[i][1][1] = dp[i - 1][1][0] + nums[i - 1];
			dp[i][1][0] = max(dp[i - 1][1][1], dp[i - 1][1][0]);
		}
		
		for (int i = 2; i <= nums.size(); ++i)
		{
		    dp[i][0][1] = dp[i - 1][0][0] + nums[i - 1];
			dp[i][0][0] = max(dp[i - 1][0][1], dp[i - 1][0][0]);
		}

		return max(max(dp[nums.size()][0][1], dp[nums.size()][0][0]), max(dp[nums.size() - 1][1][0], dp[nums.size() - 1][1][1]));
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {1,2,3,4};
	cout << s.rob(v);
	return 0;
}