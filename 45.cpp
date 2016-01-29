#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int steps = 0, curEnd = 0, curFarthest = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) 
        {
            curFarthest = max(curFarthest, i + nums[i]);
            
            if (i == curEnd) 
            {
                steps++;
                curEnd = curFarthest;
            }
        }
        
        return steps;
    }
};


/* Time O(N^2)
class Solution {
public:
    int jump(vector<int>& nums)
    {
    	std::vector<int> distance(nums.size(), numeric_limits<int>::max());

    	int n = nums.size();
    	for (int i = n - 1; i >= 0; --i)
    	{
    		if (i + nums[i] >= n - 1)
    			distance[i] = 1;
    		else
    		{
    			for (int k = 1; k <= nums[i]; ++k)
    				distance[i] = min(distance[i], distance[i + k] + 1);
    		}
    	}

    	return distance[0];
    }
};
*/

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {2, 3, 1, 1, 4};
	cout << s.jump(v);
	return 0;
}