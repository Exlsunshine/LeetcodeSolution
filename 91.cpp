#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
    	if (s.length() == 0)
    		return 0;
    	if (s.length() == 1)
    		return s[0] == 0 ? 0 : 1;

    	int *dp = new int[s.length()];
    	dp[0] = 1;

    	if ((s[0] - '0') * 10 + s[1] - '0' <= 26)
    		dp[1] = 2;
    	else
    		dp[1] = 1;

    	for (int i = 2; i < s.length(); ++i)
    	{
    		if (s[i] == '0')
    			dp[i] = dp[i - 2];
    		else if (s[i - 1] == '0')
    			dp[i] = dp[i - 1];
    		else
    			dp[i] = dp[i - 1] + (((s[0] - '0') * 10 + s[1] - '0' <= 26) ? dp[i - 2] : 0);
    	}

    	return dp[s.length() - 1];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.numDecodings("1298095345");
	return 0;
}