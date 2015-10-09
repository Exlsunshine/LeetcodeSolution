#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
    	int low = 0, high = nums.size() - 1;

    	while (low <= high)
    	{
    		int mid = (high - low) / 2 + low;

    		if (nums[mid] == target)
    			return true;
    		else
    		{
    			if (nums[mid] > nums[low])
    			{
    				if (target >= nums[low] && target < nums[mid])
    					high = mid - 1;
    				else
    					low = mid + 1;
    			}
    			else if (nums[mid] < nums[low])
    			{
    				if (target > nums[mid] && target <= nums[high])
    					low = mid + 1;
    				else
    					high = mid - 1;
    			}
    			else
    				low++;
    		}
    	}

    	return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;

	std::vector<int> v = {4,5,1,2};
	bool b = s.search(v, 4);
	cout << b << endl;
	return 0;
}