#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 * brute force O(N^2)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 1; j <= k && i + j < nums.size(); ++j)
            {
                if (abs(nums[i] - nums[i + j]) <= t)
                    return true;
            }
        }

        return false;
    }
};
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if (nums.size() == 0 || k <= 0)
            return false;
            
        set<int> bst;

        for (int i = 0; i < nums.size(); ++i)
        {
            int element = nums[i];
            
            // Find the first item that >= (element + t)
            set<int>::iterator lowerItr = bst.lower_bound(element - t);

            if ((lowerItr != bst.end()))
            {
                if (abs(*lowerItr - element) <= t)
                    return true;
            }
            
            bst.insert(element);
            if (i >= k)
                bst.erase(nums[i - k]);
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}