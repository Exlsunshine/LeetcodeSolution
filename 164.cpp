#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.size() < 2)
            return 0;
            
    	int minVal = numeric_limits<int>::max();
    	int maxVal = numeric_limits<int>::min();
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		minVal = min(minVal, nums[i]);
    		maxVal = max(maxVal, nums[i]);
    	}
    	int step = ceil((maxVal - minVal) / (nums.size() - 1));

    	std::vector<int> bucketMinVal(nums.size() - 1, numeric_limits<int>::max());
    	std::vector<int> bucketMaxVal(nums.size() - 1, numeric_limits<int>::min());
		for (int i = 0; i < nums.size(); ++i)
    	{
    		bucketMinVal[(nums[i] - minVal) / (step + 1)] = min(bucketMinVal[(nums[i] - minVal) / (step + 1)], nums[i]);
    		bucketMaxVal[(nums[i] - minVal) / (step + 1)] = max(bucketMaxVal[(nums[i] - minVal) / (step + 1)], nums[i]);
    	}

    	int maxGap = bucketMaxVal[0] - bucketMinVal[0];;
    	int previousUpperBound = bucketMaxVal[0];
    	for (int i = 1; i < nums.size() - 1; ++i)
    	{
    		if (bucketMinVal[i] == numeric_limits<int>::max() || bucketMaxVal[i] == numeric_limits<int>::min())
    			continue;
    		maxGap = max(maxGap, bucketMinVal[i] - previousUpperBound);
    		previousUpperBound = bucketMaxVal[i];
    	}

    	return maxGap;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {9, 12, 31, 7, 20};
	cout << s.maximumGap(v);

	return 0;
}