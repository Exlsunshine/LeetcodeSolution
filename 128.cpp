#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <utility>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
    	unordered_map<int, int> map;
    	int maxLength = numeric_limits<int>::min();

    	for (int i = 0; i < nums.size(); ++i)
    	{
    		// duplicate
            unordered_map<int, int>::iterator gotRight = map.find(nums[i]);
            if (gotRight != map.end())
                continue;

    		unordered_map<int, int>::iterator gotSmall = map.find(nums[i] - 1);
    		unordered_map<int, int>::iterator gotLarge = map.find(nums[i] + 1);

    		int cntSmall = gotSmall == map.end() ? 0 : gotSmall->second;
    		int cntLarge = gotLarge == map.end() ? 0 : gotLarge->second;

    		int sum = cntSmall + 1 + cntLarge;
    		maxLength = max(maxLength, sum);

    		map.insert(make_pair(nums[i], sum));

    		if (cntSmall != 0)
    			map[nums[i] - cntSmall] = sum;
    		if (cntLarge != 0)
    			map[nums[i] + cntLarge] = sum;
    	}

    	return maxLength;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {100, 4, 200, 1, 3, 2};
	cout << s.longestConsecutive(v);

	return 0;
}