#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
    	bool result = false;
    	for (int i = 0; i < board.size(); ++i)
    	{
    		for (int j = 0; j < board[0].size(); ++j)
    		{
    			result = false;
    			search(board, i, j, word, 0, result);
    			if (result)
    				return true;
    		}
    	}
    	

    	return result;
    }
private:
	void search(std::vector<std::vector<char>> &board, int x, int y, const string &word, int index, bool &result)
	{
		if (index == word.length())
		{
			result = true;
			return;
		}

		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
			return ;

		if (board[x][y] == word[index])
		{
			char c = board[x][y];
			board[x][y] = '#';
			index++;
			if (index == word.length())
			{
				result = true;
				return ;
			}

			search(board, x + 1, y, word, index, result);
			if (result)
				return;
			search(board, x - 1, y, word, index, result);
			if (result)
				return;
			search(board, x, y + 1, word, index, result);
			if (result)
				return;
			search(board, x, y - 1, word, index, result);

			board[x][y] = c;
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;

	std::vector<std::vector<char>> board;
	board.push_back(std::vector<char>{'A','B','C','E'});
	board.push_back(std::vector<char>{'S','F','C','S'});
	board.push_back(std::vector<char>{'A','D','E','E'});
	cout << s.exist(board, "ABCED");
	return 0;
}