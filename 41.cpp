#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
    	if (nums.size() == 0)
    		return 1;

    	int i = 0;
    	while (i < nums.size())
    	{
    		if (i + 1 == nums[i])
    			i++;
    		else if (nums[i] <= 0 || nums[i] > nums.size())
    			i++;
    		else
    		{
    			int temp = nums[nums[i] - 1];
    			nums[nums[i] - 1] = nums[i];
    			nums[i] = temp;
    		}
    	}

    	for (i = 0; i < nums.size(); ++i)
    	{
    		if (i + 1 != nums[i])
    			break;
    	}

    	return i + 1;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {3,4,-1,1};
	cout << s.firstMissingPositive(v);
	return 0;
}