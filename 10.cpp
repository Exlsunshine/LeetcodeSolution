#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
    	if (p.length() == 0)
    		return s.length() == 0;

    	if (p[1] == '*')
    	{
    		return ((s.length() > 0 && isEqual(s[0], p[0]) && isMatch(s.substr(1), p))
    			|| (isMatch(s, p.substr(2))));
    	}
    	else
    		return (s.length() > 0 && isEqual(s[0], p[0]) && isMatch(s.substr(1), p.substr(1)));
    }

private:
	bool isEqual(char c1, char c2)
	{
		return (c1 == c2 || c2 == '.');
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}