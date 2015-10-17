#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int fi = 0, se = 1, th = nums.size() - 1;
        int mostLike = nums[fi] + nums[se] + nums[th];
        
        sort(nums.begin(), nums.end());
        while (th - fi > 1)
        {
            int first;
            int second;
            int third;

            third = th;
            first = fi;
            second = fi + 1;

            while (third - second > 0)
            {
                int sum = nums[first] + nums[second] + nums[third];
                mostLike = (abs(sum - target) > abs(mostLike - target) ? mostLike : sum);
                
                if (sum > target)
                    third--;
                else if (sum == target)
                    return target;
                else
                    second++;
            }

            if (nums[fi] + nums[se] + nums[th] < target)
            {
                fi++;
                se++;
            }
            else
                th--;

        }
        
        return mostLike;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {-3,0,1,2};
	cout << s.threeSumClosest(v, 1);
	return 0;
}
