#include <iostream>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
    	int n = 9;
    	std::vector<std::vector<bool>> rowsOccupied(n, std::vector<bool>(n, false));
    	std::vector<std::vector<bool>> colsOccupied(n, std::vector<bool>(n, false));
    	std::vector<std::vector<bool>> subsOccupied(n, std::vector<bool>(n, false));

    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			if (board[i][j] != '.')
    			{
    				rowsOccupied[i][board[i][j] - '0' - 1] = true;
    				colsOccupied[j][board[i][j] - '0' - 1] = true;
    				subsOccupied[i / 3 * 3 + j / 3][board[i][j] - '0' - 1] = true;
    			}
    		}
    	}

    	backtracking(0, 0, board, rowsOccupied, colsOccupied, subsOccupied);
    }

private:
	bool backtracking(int i, int j, std::vector<std::vector<char>> &board, std::vector<std::vector<bool>> &rowsOccupied,
		std::vector<std::vector<bool>> &colsOccupied, std::vector<std::vector<bool>> &subsOccupied)
	{
        if (j >= board.size())
		    return backtracking(i + 1, 0, board, rowsOccupied, colsOccupied, subsOccupied);
        if (i >= board.size())
        	return true;
                    
		if (board[i][j] == '.')
		{
			for (int k = 1; k <= 9; ++k)
			{
				if (!rowsOccupied[i][k - 1] && !colsOccupied[j][k - 1] && !subsOccupied[i / 3 * 3 + j / 3][k - 1])
				{
					rowsOccupied[i][k - 1] = true;
					colsOccupied[j][k - 1] = true;
					subsOccupied[i / 3 * 3 + j / 3][k - 1] = true;
					board[i][j] = k + '0';
					
					if (backtracking(i, j + 1, board, rowsOccupied, colsOccupied, subsOccupied))
						return true;
					
					rowsOccupied[i][k - 1] = false;
					colsOccupied[j][k - 1] = false;
					subsOccupied[i / 3 * 3 + j / 3][k - 1] = false;
					board[i][j] = '.';
				}
			}
			
			return false;
		}
		else
		    return backtracking(i, j + 1, board, rowsOccupied, colsOccupied, subsOccupied);
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}