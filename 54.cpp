#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
    	std::vector<int> ans;

        if (matrix.size() == 0)
            return ans;
            
    	int i = 0, j = 0;
    	int left = 0, right = matrix[0].size() - 1;
    	int top = 0, bottom = matrix.size() - 1;
        
        int cnt = 0;
        int total = matrix[0].size() * matrix.size();
    	while (cnt < total)
    	{
    		while (j <= right && cnt < total)
    		{
    			ans.push_back(matrix[i][j]);
    			cnt++;
    			j++;
    		}
    		j--;
    		top++;

    		i++;
    		while (i <= bottom && cnt < total)
    		{
    			ans.push_back(matrix[i][j]);
    			cnt++;
    			i++;
    		}
    		i--;
    		right--;

    		j--;
    		while (j >= left && cnt < total)
    		{
    			ans.push_back(matrix[i][j]);
    			cnt++;
    			j--;
    		}
    		j++;
    		bottom--;

    		i--;
    		while (i >= top && cnt < total)
    		{
    			ans.push_back(matrix[i][j]);
    			cnt++;
    			i--;
    		}
    		i++;
    		left++;
    		j++;
    	}
    	if (cnt < total)
    	    ans.push_back(matrix[i][j]);

    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<std::vector<int>> matrix;
	std::vector<int> v = {1,2,3};
	std::vector<int> v2 = {4,5,6};
	std::vector<int> v3 = {7,8,9};

	matrix.push_back(v);
	matrix.push_back(v2);
	matrix.push_back(v3);

	s.spiralOrder(matrix);
	return 0;
}