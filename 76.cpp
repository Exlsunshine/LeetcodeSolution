#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
    	int tHash[128];
    	memset(tHash, 0, sizeof(int) * 128);

    	for (int i = 0; i < t.size(); ++i)
    		tHash[t[i]]++;
    	int counter = t.size();

    	int start = 0, end = 0;
    	int ansIndex = 0, ansLength = numeric_limits<int>::max();
    	while (end < s.length())
    	{
    		if (tHash[s[end]] > 0)
    			counter--;
    		tHash[s[end]]--;

    		while (counter == 0)
    		{
    			if (end - start + 1 < ansLength)
    			{
    				ansLength = end - start + 1;
    				ansIndex = start;
    			}

    			if (tHash[s[start]] > 0)
    				counter++;
    			tHash[s[start]]++;
    		}
    	}

    	if (ansLength == numeric_limits<int>::max())
    		return "";
    	else
    		return s.substr(ansIndex, ansLength);
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}