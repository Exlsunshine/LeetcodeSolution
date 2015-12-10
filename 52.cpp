#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n)
    {
    	std::vector<std::vector<char>> map(n, std::vector<char>(n, '.'));
    	std::vector<bool> occupiedCol(n, false);
    	std::vector<bool> occupiedDiagnal1(2 * n, false);
    	std::vector<bool> occupiedDiagnal2(2 * n, false);

    	return backtracking(map, 0, 0, 1, n, occupiedCol, occupiedDiagnal1, occupiedDiagnal2);
    }

private:
	int backtracking(std::vector<std::vector<char>> &map, int row, int col, int deepth, const int &n, 
		std::vector<bool> &occupiedCol, std::vector<bool> &occupiedDiagnal1, std::vector<bool> &occupiedDiagnal2)
	{
		if (row >= n)
			return 0;

		int cnt = 0;

		// Search every row.
		for (int i = col; i < n; ++i)
		{
			if (occupiedCol[i])
				continue;

			if (occupiedDiagnal1[n + row - i])
				continue;

			if (occupiedDiagnal2[n + row + i])
				continue;

			if (deepth == n)
				cnt++;
			else
			{
				map[row][i] = 'Q';
				occupiedCol[i] = true;
				occupiedDiagnal1[n + row - i] = true;
				occupiedDiagnal2[n + row + i] = true;
				cnt += backtracking(map, row + 1, 0, deepth + 1, n, occupiedCol, occupiedDiagnal1, occupiedDiagnal2);
				occupiedCol[i] = false;
				occupiedDiagnal1[n + row - i] = false;
				occupiedDiagnal2[n + row + i] = false;
				map[row][i] = '.';
			}
		}

		return cnt;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.totalNQueens(10) << endl;
	return 0;
}