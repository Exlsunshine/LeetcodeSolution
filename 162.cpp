#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        return findPeek(nums, 0, nums.size() - 1);
    }

private:
	int findPeek(vector<int> v, int i, int j)
	{
		if (i > j)
			return -1;

		int mid = (i + j) / 2;
		int left_neighbour  = mid - 1 < 0 ? INT_MIN : v[mid - 1];
		int right_neighbour = mid + 1 > v.size() ? INT_MIN : v[mid + 1];

		if (left_neighbour <= v[mid] && right_neighbour <= v[mid])
			return mid;

		int idx = findPeek(v, i, mid - 1);
		if (idx == -1)
			return findPeek(v, mid + 1, j);
		else
			return idx;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	int idx = s.findPeakElement(v);
	cout << "Index is " << idx;
	return 0;
}