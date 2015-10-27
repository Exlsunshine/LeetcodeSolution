#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;

        for (int i = 0; i < length; ++i)
        {
            for (int j = length - 1; j >= 0; --j)
            {
                int subTarget = target - nums[i] - nums[j];

                int m = i + 1, n = j - 1;
                while (m < n)
                {
                    if (nums[m] + nums[n] == subTarget)
                    {
                        ans.push_back(std::vector<int>{nums[i], nums[m], nums[n], nums[j]});
        
                        while (m + 1 < length && nums[m] == nums[m + 1])
                            m++;
                        while (n - 1 >= 0 && nums[n] == nums[n - 1])
                            n--;

                        m++;
                        n--;
                    }
                    else if (nums[m] + nums[n] > subTarget)
                        n--;
                    else
                        m++;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> ans = s.fourSum(v, 0);

    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }

	return 0;
}