#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) 
    {
    	int m = matrix.size();
    	int n = matrix[0].size();
    	int i = 0, j = m - 1;
    	int mid = 0;

    	while (i <= j)
    	{
    		mid = (i + j) / 2;
    		if (matrix[mid][0] > target)
    			j = mid - 1;
    		else if (matrix[mid][0] == target)
    			return true;
    		else
    		{
    			if (matrix[mid][n - 1] > target)
    				break;
    			else if (matrix[mid][n - 1] == target)
    				return true;
    			else
    				i = mid + 1;
    		}
    	}

    	if (i > j)
    		return false;
    	else
    	{
    		i = 0, j = n - 1;

    		while (i <= j)
    		{
    			int m = (i + j) / 2;
    			if (matrix[mid][m] > target)
    				j = m - 1;
    			else if (matrix[mid][m] == target)
    				return true;
    			else
    				i = m + 1;
    		}
    	}

    	return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {1, 3, 5};
	std::vector< std::vector<int> > vv;
	vv.push_back(v);
	cout << (s.searchMatrix(vv, 4) == 0);
	return 0;
}