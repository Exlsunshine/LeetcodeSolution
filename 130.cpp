#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        if (board.size() == 0)
            return;
        if (board[0].size() == 0)
            return;
		
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
    		dfs(board, i, board[0].size() - 1, visited, true);

    	// the rest point
		for (int i = 1; i < board.size() - 1; ++i)
			for (int j = 1; j < board[i].size() - 1; ++j)
				dfs(board, i, j, visited, false);

    	for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
				cout << board[i][j] << " ";
			cout << endl;
		}
    }

private:
	void dfs(std::vector<std::vector<char>> &board, int row, int col, std::vector<std::vector<bool>> &visited, bool isAtBounder)
	{
		if (row < 0 || row >= board.size())
			return;
		if (col < 0 || col >= board[row].size())
			return;
		if (visited[row][col])
			return;

		stack<pair<int, int>> stk;
		stk.push(make_pair(row, col));
		
		while (!stk.empty())
		{
			pair<int, int> point = stk.top();
			stk.pop();

			int i = point.first;
			int j = point.second;

			if (visited[i][j])
				continue;

			visited[i][j] = true;
			if (board[i][j] == 'O')
			{
				if (!isAtBounder)
					board[i][j] = 'X';

                if (i - 1 >= 0 && i - 1 < board.size() && !visited[i - 1][j])
				    stk.push(make_pair(i - 1, j));
				if (i + 1 >= 0 && i + 1 < board.size() && !visited[i + 1][j])
				    stk.push(make_pair(i + 1, j));
				if (j - 1 >= 0 && j - 1 < board[row].size() && !visited[i][j - 1])
				    stk.push(make_pair(i, j - 1));
				if (j + 1 >= 0 && j + 1 < board[row].size() && !visited[i][j + 1])
				    stk.push(make_pair(i, j + 1));
			}	
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
	cout << endl << endl;

	Solution s;
	s.solve(v);

	return 0;
}