#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector< vector<char> >& grid)
    {
    	if (grid.size() == 0)
    		return 0;
    	
    	int m = grid.size();
    	int n = grid[0].size();
    	int cnt = 0;

    	for (int i = 0; i < m; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			bool hasCount = false;
    			dfs(grid, cnt, i, j, hasCount);
    		}
    	}

    	return cnt;
    }
private:
	void dfs(std::vector< std::vector<char> > &grid, int &cnt, int m, int n, bool &hasCount)
	{
		if (m >= grid.size() || m < 0 || n >= grid[0].size() || n < 0)
			return;

		if (grid[m][n] == '1')
		{
			if (!hasCount)
			{
				cnt++;
				hasCount = true;
			}

			grid[m][n] = '2';
			dfs(grid, cnt, m - 1, n, hasCount);
			dfs(grid, cnt, m + 1, n, hasCount);
			dfs(grid, cnt, m, n - 1, hasCount);
			dfs(grid, cnt, m, n + 1, hasCount);
		}
	}
};

int main(int argc, char const *argv[])
{
	int m, n;
	cin >> m >> n;

	std::vector< std::vector<char> > v(m, std::vector<char>(n, '0'));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];

	Solution s;
	cout << s.numIslands(v) << endl;
	return 0;
}