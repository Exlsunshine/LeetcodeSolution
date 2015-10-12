#include <iostream>
#include <vector>

using namespace std;


void print(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
    	return findKth(nums, 0, nums.size() - 1, k);
    }
private:

	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	int findKth(std::vector<int> v, int start, int end, int k)
	{
		int i = start;
		int j  = end;
		int baseVal = v[start];
		int temp;

		while (i < j)
		{

			while (v[j] > baseVal && i < j)
				j--;

			while (v[i] <= baseVal && i < j)
				i++;

			if (i >= j)
				break;
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}

		v[start] = v[i];
		v[i] = baseVal;

//		print(v);

		if (k < (end - i + 1))
			return findKth(v, i + 1, end, k);
		else if (k > (end - i + 1))
			return findKth(v, start, i - 1, k - (end - i + 1));
		else
			return v[end - (k - 1)];
	}
};


int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {3, 2, 1, 5, 6, 4};
	cout << s.findKthLargest(v, 3) << endl;
	return 0;
}