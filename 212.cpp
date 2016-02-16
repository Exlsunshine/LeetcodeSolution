#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
    	Trie *root = new Trie('-');
    	for (int i = 0; i < words.size(); ++i)
    		insert(words[i], root);

    	unordered_set<string> set;

    	for (int i = 0; i < board.size(); ++i)
    	{
			for (int j = 0; j < board[0].size(); ++j)
    		{
    		  //  cout << i << "\t" << j << endl;
    			std::vector<std::vector<bool>> isVisited(board.size(), std::vector<bool>(board[0].size(), false));
    			backtracking(i, j, "", isVisited, root, board, set);
    			
    			if (set.size() == words.size())
    			{
    			    i = board.size();
    			    j = board[0].size();
    			    break;
    			}
    		}
    	}

        std::vector<string> ans(set.begin(), set.end());
		return ans;
    }

private:
    class Trie;
	void backtracking(int row, int col, string prefix, std::vector<std::vector<bool>> &isVisited, Trie *root,
		const std::vector<std::vector<char>> &board, unordered_set<string> &set)
	{
	   // cout << prefix << endl;
		if (row >= board.size() || col >= board[0].size())
			return ;
		if (isVisited[row][col])
			return ;

		prefix += board[row][col];
		int status = exist(prefix, root);
		if (status == -1)
			return ;
		else if (status == 0)
			set.insert(prefix);

		isVisited[row][col] = true;
		backtracking(row, col - 1, prefix, isVisited, root, board, set);
		backtracking(row, col + 1, prefix, isVisited, root, board, set);
		backtracking(row - 1, col, prefix, isVisited, root, board, set);
		backtracking(row + 1, col, prefix, isVisited, root, board, set);
		isVisited[row][col] = false;
	}

	class Trie
	{
	public:
		Trie(char c)
		{
			ch = c;
			memset(child, NULL, sizeof(Trie *) * 26);
			leaf = false;
		}

		char ch;
		bool leaf;
		Trie *child[26];
	};
	
	void insert(string str, Trie *rt)
	{
	    Trie *root = rt;
		for (int i = 0; i < str.length(); ++i)
		{
			char ch = str[i];

			if (root->child[ch - 'a'] == NULL)
				root->child[ch - 'a'] = new Trie(ch);

			root = root->child[ch - 'a'];
		}
		
		root->leaf = true;
	}

	// -1 means not found
	// 0 means found at ternimal nodes
	// 1 means found at inner nodes
	int exist(string prefix, Trie *rt)
	{
	    Trie *root = rt;
		for (int i = 0; i < prefix.size(); ++i)
		{
		    char ch = prefix[i];

			if (root->child[ch - 'a'] == NULL)
				return -1;
			else
				root = root->child[ch - 'a'];
		}
        
        return (root->leaf ? 0 : 1);
	}
};

int main(int argc, char const *argv[])
{
	/*
	vector<char> v1 = {'o','a','a','n'};
	vector<char> v2 = {'e','t','a','e'};
	vector<char> v3 = {'i','h','k','r'};
	vector<char> v4 = {'i','f','l','v'};
	vector<vector<char>> board{v1, v2, v3, v4};
	vector<string> words = {"oath","pea","eat","rain"};
	 */

	vector<char> v1 = {'a','b'};
	vector<char> v2 = {'c','d'};
	vector<vector<char>> board{v1, v2};
	vector<string> words = {"ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"};

	Solution solution;
	solution.findWords(board, words);

	return 0;
}