#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
    	std::vector<std::vector<int>> v;
    	sort(nums.begin(), nums.end());

    	for (int i = 0; i < nums.size(); ++i)
    	{
            if (i != 0 && nums[i] != nums[i - 1])
            {
                int target = 0 - nums[i];
        		int low = i + 1;
        		int high = nums.size() - 1;

        		while (low < high)
        		{
        			if (nums[low] + nums[high] == target)
        			{
                        v.push_back(std::vector<int>{nums[i], nums[low], nums[high]});

        				while (low < high && nums[low] == nums[low + 1])
        					low++;
        				while (low < high && nums[high] == nums[high - 1])
        					high--;

        				low++;
        				high--;
        			}
        			else if (nums[low] + nums[high] < target)
        				low++;
        			else
        				high--;
        		}
            }
    	}

        return v;
    }
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {-1, 0, 1, 2, -1, -4};

	Solution s;
	std::vector<std::vector<int>> vr = s.threeSum(v);

	for (int i = 0; i < vr.size(); ++i)
    {
        for (int j = 0; j < vr[i].size(); ++j)
		  cout << vr[i][j] << " ";
        cout << endl;
	}

    return 0;
}