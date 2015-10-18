#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(std::vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl << endl;
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        std::vector<std::vector<int>> ans;
        sort(nums.begin(), nums.end());
        generatePermutations(nums, 0, nums.size() - 1, ans);

        return ans;
    }
private:
    void generatePermutations(std::vector<int> nums, const int begin, const int end, std::vector<std::vector<int>> &ans)
    {
        if (begin > end)
        {
            ans.push_back(nums);
            return ;
        }

        for (int i = begin; i <= end; ++i)
        {
            if (nums[i] == nums[i - 1] && i != begin)
                continue;
            if (nums[i] == nums[begin] && i != begin)
                continue;

            swap(nums[begin], nums[i]);
            generatePermutations(nums, begin + 1, end, ans);
            //swap(nums[begin], nums[i]);       
        }
    }
};


int main(int argc, char const *argv[])
{
    std::vector<int> v = {0,0,1,1,2,2};
    Solution s;
    s.permuteUnique(v);
	return 0;
}