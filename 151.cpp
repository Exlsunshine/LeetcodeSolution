#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s)
    {
    	int i, j;
    	for (i = 0; i < s.length(); )
    	{
    		if (s[i] == ' ')
    			continue;

    		for (j = i + 1; j < s.length(); ++j)
    		{
    			if (s[j] == ' ')
    				break;
    		}

    		int len = j - i;
    		for (int k = i; k < len / 2; ++k)
    		{
    			char c = s[k];
    			s[i] = s[j - 1 - k];
    			s[j - 1 - k] = c;
    		}

    		i = j + 1;

			cout << s << endl;
 	    }

 	    
 	    for (i = 0; i < s.length() / 2; ++i)
 	    {
 	    	char c = s[i];
 	    	s[i] = s[s.length() - 1 - i];
 	    	s[s.length() - 1 - i] = c;
 	    }
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str = "the sky is blue";

	cout << str << endl;
	s.reverseWords(str);
	cout << str << endl;
	return 0;
}









