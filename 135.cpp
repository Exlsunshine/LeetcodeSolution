#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings)
	{
		std::vector<int> amounts(ratings.size(), 0);

		int i = 0;
		while (i < ratings.size())
		{
			int j;
			for (j = i; j < ratings.size(); ++j)
			{
				if (j == i)
					continue;

				if (ratings[j] <= ratings[j - 1])
					continue;

				j -= 1;
				break;
			}
			j = min(j, (int)ratings.size() - 1);

			int num = 1;
			amounts[j] = num;
			for (int k = j - 1; k >= i; --k)
			{
				if (ratings[k] == ratings[k + 1])
					num = 1;
				else
					num++;

				amounts[k] = num;
			}
			amounts[i] = max(amounts[i], (i - 1 >= 0 ? amounts[i - 1] : 0) + 1);

			i = j + 1;
		}

		int sum = 0;
		for (int j = 0; j < amounts.size(); ++j)
			sum += amounts[j];

		return sum;
	}
};

int main(int argc, char const *argv[])
{
	Solution solution;
	vector<int> vector1 = {-1,0,3,3,3,2,2,1,0};
	cout << solution.candy(vector1);
	return 0;
}