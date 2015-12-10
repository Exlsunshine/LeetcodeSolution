#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
    	std::vector<bool> occupiedCol(n, false);
    	std::vector<bool> occupiedDiagnal1(2 * n, false);
    	std::vector<bool> occupiedDiagnal2(2 * n, false);
    	std::vector<std::vector<string>> ans;
    	std::vector<string> map(n, string(n, '.'));

    	backtracking(occupiedCol, occupiedDiagnal1, occupiedDiagnal2, ans, 1, 0, n, map);

    	return ans;
    }

private:
	void backtracking(std::vector<bool> &occupiedCol, std::vector<bool> &occupiedDiagnal1, std::vector<bool> &occupiedDiagnal2,
		std::vector<std::vector<string>> &ans, int deepth, int row, int n, std::vector<string> &map)
	{
		if (deepth == n + 1)
		{
		    ans.push_back(map);
		    return;
        }
        
		for (int i = 0; i < n; ++i)
		{
			if (occupiedCol[i])
				continue;

			if (occupiedDiagnal1[n + row - i])
				continue;

			if (occupiedDiagnal2[n + row + i])
				continue;

		    map[row][i] = 'Q';
			occupiedCol[i] = true;
			occupiedDiagnal1[n + row - i] = true;
			occupiedDiagnal2[n + row + i] = true;
			backtracking(occupiedCol, occupiedDiagnal1, occupiedDiagnal2, ans, deepth + 1, row + 1, n, map);
			occupiedCol[i] = false;
			occupiedDiagnal1[n + row - i] = false;
			occupiedDiagnal2[n + row + i] = false;
			map[row][i] = '.';
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<std::vector<string>> v = s.solveNQueens(10);
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << endl;

		cout << endl << endl;
	}
	return 0;
}