#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) 
    {
    	string str;
    	if (s.length() % 2 == 0)
    		str = s;
    	else
    	{
	    	str = string(s.length() * 2 + 1, '#');
	    	int k = 0;
	    	for (int i = 0; i < s.length(); ++i)
	    	{
	    		str[k++] = '#';
	    		str[k++] = s[i];
	    	}
	    	str[k] = '#';
	    }

    	int maxLength = 0;
    	int maxIndex = 0;

    	for (int i = 0; i < str.length() && str.length() - i >= maxLength; ++i)
    	{
    		int j = 1;

    		while (i - j >= 0 && i + j < str.length())
    		{
    			if (str[i - j] == str[i + j])
    				j++;
    			else
    				break;
    		}

    		if (j - 1 > maxLength)
    		{
    			maxLength = j - 1;
    			maxIndex = i;
    		}
    	}

    	cout << maxLength << endl;
    	cout << maxIndex << endl;
    	cout << str << endl;

    	if (s.length() % 2 == 0)
    		return str.substr(maxIndex - maxLength, 2 * maxLength + 1);

    	string ans(maxLength, ' ');
    	int k = 0;
    	for (int i = maxIndex - maxLength; i <= maxIndex + maxLength; i += 2)
    	{
    		cout << k << "\t" << i << "\t" << str[i + 1] << endl;
    		ans[k++] = str[i + 1];
		}

    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.longestPalindrome("eabcb") << endl;
	return 0;
}