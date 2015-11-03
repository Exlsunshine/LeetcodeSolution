#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
    	int n = s.length();
    	int maxLength = 0;
    	int currentLength = 0;
    	int startIdx = 0;

    	int hits[256];
    	memset(hits, -1, sizeof(int) * 256);

    	for (int i = 0; i < n; ++i)
    	{
    		if (hits[s[i]] == -1)
    		{
    			currentLength++;
    			if (currentLength > maxLength)
    				maxLength = currentLength;
    			hits[s[i]] = i;
    		}
    		else
    		{
    			int lastIdx = hits[s[i]];
    			for (int j = startIdx; j <= lastIdx; ++j)
    				hits[s[j]] = -1;
    			currentLength = i - (lastIdx + 1) + 1;
    			hits[s[i]] = i;
    			startIdx = lastIdx + 1;
    		}

    		cout << i << "\ta " << hits['a'] << "\tb " << hits['b'] << "\tc " << hits['c'] << endl;
    	}

    	return maxLength;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str = "abcabcbbzxe";

	cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}