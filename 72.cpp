#include <iostream>

using namespace std;

class Solution 
{
public:
	int minDistance(string word1, string word2) 
    {
    	int len1 = word1.length();
    	int len2 = word2.length();

    	int max_len = len1 + len2;
    	int **d = new int*[max_len + 1];
    	for (int i = 0; i < max_len + 1; ++i)
    	{
    		d[i] = new int[max_len + 1];
    		memset(d[i], 0, sizeof(int) * (max_len + 1));
    	}

    	for (int i = 0; i < max_len; ++i)
    	{
    		d[i][0] = i;
    		d[0][i] = i;
    	}

    	for (int i = 1; i <= len1; ++i)
    	{
    		for (int j = 1; j <= len2; ++j)
    		{
    			if (word1[i - 1] == word2[j - 1])
    				d[i][j] = d[i - 1][j - 1];
    			else
    			{
    				int minimum = min(d[i - 1][j - 1], d[i - 1][j]);
    				minimum = min(minimum, d[i][j - 1]);
    				d[i][j] = minimum + 1;
    			}
    		}
    	}
    	
    	return d[len1][len2];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.minDistance("join", "john") << endl;
	return 0;
}