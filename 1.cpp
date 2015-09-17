#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> map;

    	for (int i = 0; i < nums.size(); i++)
    	{
    		unordered_map<int, int>::const_iterator result = map.find(target - nums[i]);
    		if (result == map.end())
    			map.emplace(nums[i], i);
    		else
    		{
    			vector<int> ret;
    			int less_index = i <= result->second ? i : result->second;
    			int large_index = i > result->second ? i : result->second;
    			ret.push_back(less_index + 1);
    			ret.push_back(large_index + 1);
    			return ret;
    		}
    	}
    }
};

int main ()
{
	Solution s;
	vector<int> v;
	v.push_back(2);
	v.push_back(7);
	v.push_back(11);
	v.push_back(15);

	vector<int> v2 = s.twoSum(v, 9);

	cout << v2[0] << "\t" << v2[1] << endl;	
	return 0;
}
