#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
	{
		wordList.insert(endWord);
		int cnt = 1;	
		queue<string> neighbours;
		generateNeighbours(beginWord, wordList, neighbours);

		while (!neighbours.empty())
		{
			int size = neighbours.size();
			for (int i = 0; i < size; i++)
			{
				string neighbour = neighbours.front();
				neighbours.pop();

				if (neighbour == endWord)
				{
					cnt++;
					return cnt;
				}
				else
				{
					//unordered_set<string> tempList(wordList);
					generateNeighbours(neighbour, wordList, neighbours);
					//wordList = tempList;
				}
			}
			cnt++;
		}

		return 0;
	}

private:
	void generateNeighbours(string currentWord, unordered_set<string>& wordList, queue<string>& neighbours)
	{
		for (int i = 0; i < currentWord.length(); ++i)
		{
			char temp = currentWord[i];
			for (int j = 0; j < 26; ++j)
			{
				currentWord[i] = 'a' + j;
				unordered_set<string>::const_iterator target = wordList.find(currentWord);
				if (target != wordList.end())
				{
					neighbours.push(currentWord);
					wordList.erase(currentWord);
				}
			}
			currentWord[i] = temp;
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	unordered_set<string> wordList;
	wordList.insert("hot");
	wordList.insert("dot");
	wordList.insert("dog");
	wordList.insert("lot");
	wordList.insert("log");

	cout << s.ladderLength("hit", "cog", wordList);
	

	cin.get();
	cin.get();
	return 0;
}