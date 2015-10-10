#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int current = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
                nums[current++] = nums[i];
        }

        for (int i = current; i < nums.size(); ++i)
            nums[i] = 0;
    
        for (int i = 0; i < nums.size(); ++i)
            cout << nums[i] << " ";
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {0 , 0 ,1 ,2 ,3, 4 , 0 , 0, 0, 5, 0};
    s.moveZeroes(v);
	return 0;
}