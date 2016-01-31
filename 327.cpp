#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
    	if (nums.size() == 0)
    		return 0;

    	std::vector<long> sum(nums.size() + 1, 0);
    	std::vector<long> buffer(nums.size() + 1, 0);
    	for (int i = 0; i < nums.size(); ++i)
    		sum[i + 1] = sum[i] + nums[i];

    	return mergeSort(sum, buffer, 0, nums.size(), lower, upper);
    }

private:
	int mergeSort(std::vector<long> &sum, std::vector<long> &buffer,int from, int to, const int &lower, const int &upper)
	{
		if (from >= to)
			return 0;

        // divide and conquer
		int mid = (from + to) / 2;
		int cnt = 0;
		cnt += mergeSort(sum, buffer, from, mid, lower, upper);
		cnt += mergeSort(sum, buffer, mid + 1, to, lower, upper);

		// make count at here.
		int start = mid + 1;
		int end = mid + 1;
		for (int i = from; i <= mid; ++i)
		{
			while ((start <= to) && (sum[start] - sum[i] <  lower))	 start++;
			while ((end   <= to) && (sum[end]   - sum[i] <= upper))	 end++;
			cnt += end - start;
		}
		
		// merge sort.
        int i = from, j = mid + 1, k = from;
        while (i <= mid && j <= to)
        {
            if (sum[i] < sum[j])
                buffer[k++] = sum[i++];
            else
                buffer[k++] = sum[j++];
        }
        while (i <= mid)
            buffer[k++] = sum[i++];
        while (j <= to)
            buffer[k++] = sum[j++];
            
        // save the order into sum.
        copy(buffer.begin() + from, buffer.begin() + to + 1, sum.begin() + from);

		return cnt;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {-2, 5, -1};
	cout << s.countRangeSum(v, -2, 2) << endl;
	return 0;
}