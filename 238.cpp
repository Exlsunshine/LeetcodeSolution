#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
    	int last_item = 1;
    	std::vector<int> v(nums.size(), 1);
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		v[i] = last_item;
    		last_item *= nums[i];
    	}

    	last_item = 1;
    	for (int i = nums.size() - 1; i >= 0; --i)
    	{
    		v[i] *= last_item;
    		last_item *= nums[i];
    	}

    	return v;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(3);
	v.push_back(7);

	v = s.productExceptSelf(v);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";

	return 0;
}