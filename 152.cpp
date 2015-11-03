#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
    	int n = nums.size();
    	int negativeCnt = 0;
    	int negativeStartIdx = 0;
    	int negativeLastIdx = 0;
    	int subArrStartIdx = 0;
    	int maxProduct = 0;

    	for (int i = 0; i < n; ++i)
    	{
    		if (nums[i] > 0)
    			continue;
    		else if (nums[i] < 0)
    		{
    			if (negativeCnt == 0)
    				negativeStartIdx = i;
    			negativeLastIdx = i;
    			negativeCnt++;
    		}
    		else
    		{
    			maxProduct = max(maxProduct, findMaxProduct(subArrStartIdx, i - 1, negativeCnt, negativeStartIdx, negativeLastIdx, nums));
    			negativeCnt = 0;
    			negativeStartIdx = 0;
    			subArrStartIdx = i + 1;
    		}
    	}

    	if (subArrStartIdx < n)
        	maxProduct = max(maxProduct, findMaxProduct(subArrStartIdx, n - 1, negativeCnt, negativeStartIdx, negativeLastIdx, nums));

    	return maxProduct;
    }
private:
	int findMaxProduct(int start, int end, int negativeCnt, int firstNegativeIdx, int lastNegativeIdx, const std::vector<int> &nums)
	{
		if (start == end)
			return nums[start];

		int maxProduct = 1;
		if (negativeCnt % 2 == 0)
		{
			int product = 1;
			for (int i = start; i <= end; ++i)
				product *= nums[i];

			maxProduct = product;
		}
		else
		{
			int product = 1;
			for (int i = start; i < lastNegativeIdx; ++i)
				product *= nums[i];
			maxProduct = max(maxProduct, product);

			product = 1;
			for (int i = lastNegativeIdx + 1; i <= end; ++i)
				product *= nums[i];
			maxProduct = max(maxProduct, product);


			product = 1;
			for (int i = start; i < firstNegativeIdx; ++i)
				product *= nums[i];
			maxProduct = max(maxProduct, product);


			product = 1;
			for (int i = firstNegativeIdx + 1; i <= end; ++i)
				product *= nums[i];
			maxProduct = max(maxProduct, product);		
		}

		return maxProduct;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {2,3,-2,5,-1,0,0,0,5,-1,9,2,0,0};
	cout << s.maxProduct(v);
	return 0;
}