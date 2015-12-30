#include <iostream>
#include <vector>

using namespace std;

/*
    Non-recursive version.
*/
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {
            /*  Uncomment the code below this line, the algorithm is also the answer of #153 */
            while (low < high && nums[low] == nums[low + 1])
                low++;
            while (low < high && nums[high] == nums[high - 1])
                high--;
            if (low == high)
                break;
                
            if (nums[low] == nums[high])
            {
                while (low < high && nums[low] == nums[low + 1])
                    low++;

                while (low < high && nums[low] == nums[high])
                    high--;
            }
            if (low == high)
                break;
            /*  Uncomment the code above this line, the algorithm is also the answer of #153 */
                
            int mid = low + (high - low) / 2;


            // mid value locate in the left half(all the elements which are bigger than the piovt val)
            if (nums[mid] >= nums[low] && nums[mid] > nums[high])
                low = mid + 1;
            else if (nums[mid] >= nums[low] && nums[mid] < nums[high])
                break;
            else if (nums[mid] < nums[low])
                high = mid;
        }

        return nums[low];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {9,10,11,12,14,1,2,3,4,5,6,7,8};

    cout << s.findMin(v);

	return 0;
}