#include <iostream>
#include <vector>

using namespace std;

/*
    Binary search version.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int cnt =  0;
            for (int i = 0; i < nums.size(); ++i)
                cnt += (nums[i] <= mid);

            if (cnt > mid)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

/*
    Two pointers version.

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return 0;

        int low = 0, fast = 0;

        do
        {
            low = nums[low];
            fast = nums[nums[fast]];
        } while (low != fast);

        low = 0;
        while (low != fast)
        {
            low = nums[low];
            fast = nums[fast];
        }

        return low;
    }
};
*/

/*
    Time O(n^2) version.

class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		for (int j = i + 1; j < nums.size(); ++j)
    		{
    			if (nums[i] == nums[j])
    				return nums[i];
    		}
    	}

    	return 0;
    }
};
*/

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    cout << s.findDuplicate(v) << endl;

	return 0;
}