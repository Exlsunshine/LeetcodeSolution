#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
    	std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
    	
    	// top
    	for (int i = 0; i < board[0].size(); ++i)
    		dfs(board, 0, i, visited, true);
    	// bottom
    	for (int i = 0; i < board[0].size(); ++i)
    		dfs(board, board.size() - 1, i, visited, true);
    	// left
    	for (int i = 0; i < board.size(); ++i)
    		dfs(board, i, 0, visited, true);
    	// right
    	for (int i = 0; i < board.size(); ++i)
    		dfs(board, i, board[0].size(), visited, true);

    	// the rest point
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j)
				dfs(board, i, j, visited, false);

    	for (int i = 1; i < board.size() - 1; ++i)
		{
			for (int j = 1; j < board[i].size() - 1; ++j)
				cout << board[i][j] << " ";
			cout << endl;
		}
    }

private:
	void dfs(std::vector<std::vector<char>> &board, int i, int j, std::vector<std::vector<bool>> &visited, bool isAtBounder)
	{
		if (i < 0 || i >= board.size())
			return;
		if (j < 0 || j >= board[i].size())
			return;
		if (visited[i][j])
			return;
		
		visited[i][j] = true;
		if (board[i][j] == 'O')
		{
			if (!isAtBounder)
				board[i][j] = 'X';

			dfs(board, i - 1, j, visited, isAtBounder);
			dfs(board, i + 1, j, visited, isAtBounder);
			dfs(board, i, j - 1, visited, isAtBounder);
			dfs(board, i, j + 1, visited, isAtBounder);
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<std::vector<char>> v;
	std::vector<char> row;
	row.push_back('X');row.push_back('X');row.push_back('X');row.push_back('X');
	v.push_back(row);
	row.clear();
	row.push_back('X');row.push_back('O');row.push_back('O');row.push_back('X');
	v.push_back(row);
	row.clear();
	row.push_back('X');row.push_back('X');row.push_back('O');row.push_back('X');
	v.push_back(row);
	row.clear();
	row.push_back('X');row.push_back('O');row.push_back('X');row.push_back('X');
	v.push_back(row);

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";

		cout << endl;
	}
	cout << endl;

	Solution s;
	s.solve(v);

	return 0;
}