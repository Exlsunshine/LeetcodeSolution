#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {

private:
	static bool compare(int x, int y)
	{
		string strx = to_string(x);
		string stry = to_string(y);

		return strx + stry > stry + strx;
	}

public:
	string largestNumber(vector<int>& nums)
	{
		sort(nums.begin(), nums.end(), compare);
		string largest;

		for (int i = 0; i < nums.size(); ++i)
			largest = largest + to_string(nums[i]);
        for (int i = 0; i < largest.length(); i++)
            if (largest[i] != '0')
                return largest;
                
		return "0";
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {3,5,30,9,34};

	Solution s;
	cout << s.largestNumber(v) << endl;

	return 0;
}