#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
    	int k = nums.size() + 2;
    	std::vector<std::vector<int>> burst(k, std::vector<int>(k, 0));
    	std::vector<int> v(k, 0);
    	for (int i = 0, j = 1; i < nums.size(); ++i, ++j)
    		v[j] = nums[i];
    	v[0] = 1;
    	v[k - 1] = 1;

    	for (int step = 2; step < k; ++step)
    	{
    		for (int left = 0; left < k - step; ++left)
    		{
    			int right = left + step;
    			for (int i = left + 1; i < right; ++i)
    			{
    				burst[left][right] = max(
    					burst[left][right], 
    					burst[left][i] + v[left] * v[i] * v[right] + burst[i][right]);
    			}
    		}
    	}

    	return burst[0][k - 1];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {3, 1, 5, 8};

	cout << s.maxCoins(v) << endl;
	return 0;
}