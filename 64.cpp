#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
    	int row = grid[0].size();
    	int col = grid.size();
        int **m = new int*[row + 1];
        for (int i = 0; i < row + 1; ++i)
        {
        	m[i] = new int[col + 1];
        	memset(m[i], INT_MAX, sizeof(int) * col);
        }
        m[0, 1] = 0;
        m[1, 0] = 0;

        for (int i = 1; i <= row; ++i)
        {
        	for (int j = 1; j <= col; ++j)
        	{
        		m[i, j] = grid[i - 1][j - 1] + min(m[i - 1, j], m[i, j - 1]);
        	}
        }

        return m[row, col];
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}