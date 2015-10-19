#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        
    	int n = nums.size();
    	int *accumulate = new int[n];
    	memset(accumulate, 0, sizeof(int) * n);
    	accumulate[0] = nums[0];

    	for (int i = 1; i < n; ++i)
    		accumulate[i] += accumulate[i - 1] + nums[i];

    	if (accumulate[n - 1] < s)
    	    return 0;

    	int lastIndex = 0;
    	int minLength = numeric_limits<int>::max();

    	for (int i = 0; i < n; ++i)
    	{
    		if (accumulate[i] >= s)
    		{
    			while (accumulate[i] - accumulate[lastIndex] >= s)
    				lastIndex++;

       			if ((i - lastIndex + 1) < minLength)
    				minLength = i - lastIndex + 1;
    		}
    	}

    	return minLength;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {1,2,3,4,5};
	cout << s.minSubArrayLen(11, v);
	return 0;
}