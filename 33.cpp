#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
    	int low = 0, high = nums.size() - 1;

    	while (low <= high)
    	{
    		int mid = (low + high) / 2;

    		if (nums[mid] == target)
    			return mid;
    		else if (nums[mid] < target)
    		{
    			// mid is in left hand
    			if (nums[mid] >= nums[low] && nums[low] > nums[high])
    				low = mid + 1;
    			// mid is in right hand
    			else if (nums[mid] < nums[low] && nums[low] > nums[high])
    			{
    				if (target > nums[high])
    					high = mid - 1;
    				else if (target < nums[high])
    					low = mid + 1;
    				else
    					return high;
    			}
    			else
    				low = mid + 1;
    		}
    		else
    		{
    			// mid is in left hand
    			if (nums[mid] >= nums[low] && nums[low] > nums[high])
    			{
    				if (target > nums[low])
    					high = mid - 1;
    				else if (target < nums[low])
    					low = mid + 1;
    				else
    					return low;
    			}
    			// mid is in right hand
    			else if (nums[mid] < nums[low] && nums[low] > nums[high])
    			{
    				high = mid - 1;
    			}
    			else
    				high = mid - 1;
    		}
    	}

    	return -1;
    }
};

int main()
{
	Solution s;

	std::vector<int> v = {0,1,2,4,5,6,7};
	cout << s.search(v, 6);

	return 0;
}














