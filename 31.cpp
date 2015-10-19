#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


void printVector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";	
	cout << endl;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
    	perm(nums, 0, nums.size() - 1);
    }
private:
	void perm(std::vector<int> &nums, int start, int end)
	{
		if (start >= end)
			return;

    	int highBitPosition = numeric_limits<int>::min();
    	int indexI = -1, indexJ = -1;

    	for (int i = end; i >= start; --i)
    	{
    		for (int j = i - 1; j >= start; --j)
    		{
    			if (nums[i] > nums[j])
    			{
		    		if (j > highBitPosition)
		    		{
		    			indexI = i;
		    			indexJ = j;
		    			highBitPosition = j;
		    		}
		    		break;
    			}
    		}
    	}

    	if (indexI == -1)
    		sort(nums.begin() + start, nums.begin() + start + (end - start + 1));
    	else
    	{
    		swap(nums[indexI], nums[indexJ]);
    		cout << indexJ << endl;
    		perm(nums, indexJ + 1, end);
    	}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {1,2,6,4,8,2,0,4,1};
	s.nextPermutation(v);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";

	return 0;
}
