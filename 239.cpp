#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
    	std::vector<int> ans;
    	if (nums.size() == 0 || k == 0)
    	    return ans;
    	    
    	int start = 0;
    	int maxIdx = -1;
    	int maxVal = numeric_limits<int>::min();
    	int i = 0;

    	while (i < nums.size() - k + 1)
    	{
    		for (int j = start; j < i + k; ++j)
    		{
    			if (nums[j] > maxVal)
    			{
    				maxVal = nums[j];
    				maxIdx = j;
    			}
    		}
    		ans.push_back(maxVal);

    		int r = maxIdx - i;
    		if (r == 0)
    		{
    			i++;
    			start = i;
    			maxVal = numeric_limits<int>::min();
    			continue;
    		}

    		for (int j = 0; j < r; ++j)
    		{
    			if (i + k + j >= nums.size())
    			{
    				i = i + k + j;
    				break;
    			}
    			if (nums[i + k + j] > maxVal)
    			{
    				maxVal = nums[i + k + j];
    				maxIdx = i + k + j;
    			}

    			ans.push_back(maxVal);

    			if (maxIdx > i + k)
    			{
    				i = i + j + 2;
    				start = maxIdx + 1;
    				break;
    			}
    			if (j == r - 1)
    			{
    				i = i + j + 2;
    				start = i;
    				maxVal = numeric_limits<int>::min();
    			}
    		}
    	}

    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {213,233,213,45,-325,34,5,4,564,7,645,3,4,3,423,-324,32,-423,-4,23,90,3,123,-23,-4312,4,23,-1};
	s.maxSlidingWindow(v, 10);
	return 0;
}