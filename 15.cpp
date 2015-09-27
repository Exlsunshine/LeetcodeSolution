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
    		int target = 0 - nums[i];

    		int low = i + 1;
    		int high = nums.size() - 1;

    		while (low <= high)
    		{
    			if (nums[low] + nums[high] == target)
    			{

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
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,4,2,7,3};

	Solution s;
	s.threeSum(v);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	return 0;
}