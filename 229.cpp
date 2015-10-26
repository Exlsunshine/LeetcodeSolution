#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
    	int topVote1, topVote2;
    	int cnt1 = 0, cnt2 = 0;

    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (cnt1 == 0)
    			topVote1 = nums[i];
    		else if (cnt2 == 0)
    			topVote2 = nums[i];
    		else if (nums[i] == topVote1)
    			cnt1++;
    		else if (nums[i] == topVote2)
    			cnt2++;
    		else
    		{
    			cnt1--;
    			cnt2--;
    		}
		}

		cnt1 = 0;
		cnt2 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (topVote1 == nums[i])
				cnt1++;
			else if (topVote2 == nums[i])
				cnt2++;
		}

		std::vector<int> v;
		if (cnt1 > nums.size() / 3)
			v.push_back(topVote1);
		if (cnt2 > nums.size() / 3)
			v.push_back(topVote2);

		return v;
    }
};

int main()
{
	return 0;
}
