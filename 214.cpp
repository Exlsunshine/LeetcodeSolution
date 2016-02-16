#include <iostream>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) 
    {
    	string reverseStr = s;
    	reverse(reverseStr.begin(), reverseStr.end());
    	std::vector<int> next = computeNext(s + "#" + reverseStr);
    	
    	return reverseStr.substr(0, reverseStr.length() - next[next.size() - 1]) + s;
    }

private:
	std::vector<int> computeNext(string pattern)
	{
		std::vector<int> next(pattern.length(), 0);
		for (int i = 1, k = 0; i < pattern.length(); ++i)
		{
			k = next[i - 1];

			while (k > 0 && pattern[i] != pattern[k])
				k = next[k - 1];

			if (pattern[i] == pattern[k])
				k++;

			next[i] = k;
		}

		return next;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}