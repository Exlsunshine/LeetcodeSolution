#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
    	int i = 0, j = nums.size() - 1;
    	int very_begining = -1;
    	int very_ending = -1;

    	while (i <= j)
    	{
    		int mid = (i + j) / 2;

    		if (nums[mid] > target)
    			j = mid - 1;
    		else if (nums[mid] < target)
    			i = mid + 1;
    		else
    		{
    			very_begining = mid;
    			very_ending = mid;

    			if (mid - 1 >= 0 && nums[mid - 1] == target)
    			{
    				int b = i, e = mid - 1;

    				while (b <= e)
    				{
    					int m = (b + e) / 2;
    					if (nums[m] > target)
			    			e = m - 1;
			    		else if (nums[m] < target)
			    			b = m + 1;
			    		else
			    		{
			    			very_begining = m;
			    			e = m - 1;
			    		}
    				}
    			}

    			if (mid + 1 < nums.size() && nums[mid + 1] == target)
    			{
    				int b = mid + 1, e = j;

    				while (b <= e)
    				{
    					int m = (b + e) / 2;
    					if (nums[m] > target)
			    			e = m - 1;
			    		else if (nums[m] < target)
			    			b = m + 1;
			    		else
			    		{
			    			very_ending = m;
			    			b = m + 1;
			    		}
    				}
    			}

    			break;
    		}
    	}

    	return std::vector<int>{very_begining, very_ending};
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {1,2,3,3,3,3,4,5,9};
	s.searchRange(v, 3);


	return 0;
}