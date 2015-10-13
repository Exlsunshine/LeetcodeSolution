#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
            
        std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(2, 0));
        dp[1][0] = 0;
        dp[1][1] = nums[0];

        for (int i = 2; i <= nums.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }

        return max(dp[nums.size()][0], dp[nums.size()][1]);
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 2, 5, 5, 1, 3, 6};
    Solution s;
    cout << s.rob(v);
    return 0;
}