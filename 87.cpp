#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2)
    {
    	// 查看长度是否一致且不为零
    	if (s1.length() != s2.length() || s1.length() == 0 || s2.length() == 0)
    		return false;

    	// 查看元素是否一致
    	std::vector<int> chCnt(128, 0);
    	for (int i = 0; i < s1.length(); ++i)
    	{
    		chCnt[s1[i]]++;
    		chCnt[s2[i]]--;
    	}
    	for (int i = 0; i < 128; ++i)
    	{
    		if (chCnt[i] != 0)
    			return false;
    	}

    	// 递归返回条件
    	if (s1.length() == 1 && s2.length() == 1)
    		return s1[0] == s2[0];

    	string s1Front, s1Rear, s1FrontPair, s1RearPair;
    	int strLen = s1.length();
    	for (int i = 1; i < strLen; ++i)
    	{
    		s1Front = s1.substr(0, i);
	    	s1Rear = s1.substr(i, strLen - i);
	    	findPairs(s2, s1Front, s1Rear, s1FrontPair, s1RearPair);

	    	bool isAScramble = isScramble(s1Front, s1FrontPair) && isScramble(s1Rear, s1RearPair);
	    	if (isAScramble)
	    		return isAScramble;
    	}
    	
        string s1swap = s2;
        string s2swap = s1;
        s1Front, s1Rear, s1FrontPair, s1RearPair;
    	strLen = s1swap.length();
    	for (int i = 1; i < strLen; ++i)
    	{
    		s1Front = s1swap.substr(0, i);
	    	s1Rear = s1swap.substr(i, strLen - i);
	    	findPairs(s2swap, s1Front, s1Rear, s1FrontPair, s1RearPair);

	    	bool isAScramble = isScramble(s1Front, s1FrontPair) && isScramble(s1Rear, s1RearPair);
	    	if (isAScramble)
	    		return isAScramble;
    	}
    	
    	return false;
    }

private:
	void findPairs(const string &s2, const string &s1Front, const string &s1Rear, string &s1FrontPair, string &s1RearPair)
	{
		int strLen = s1Front.length() + s1Rear.length();
		int lastCnt = 0;
    	// 从s2的前面开始匹配s1Front
    	for (int i = 0; i < strLen; ++i)
    	{
    		// 没有匹配成功，跳出循环，从s2的后面开始匹配s1Front
    		if (i >= s1Front.length())
    		{
    			s1FrontPair = s2.substr(s1Rear.length(), strLen - s1Rear.length());
    			s1RearPair = s2.substr(0, s1Rear.length());
    			break;
    		}

    		int currentCnt = 0;
    		for (int j = 0; j < s1Front.length(); ++j)
    		{
    			if (s2[i] == s1Front[j])
    			{
    				currentCnt++;
    				break;
    			}
    		}

    		lastCnt = (currentCnt == 0) ? 0 : (lastCnt + 1);

    		if (lastCnt == s1Front.length())
    		{
    			s1FrontPair = s2.substr(0, s1Front.length());
    			s1RearPair = s2.substr(s1Front.length(), strLen - s1Front.length());
    			break;
    		}
    	}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;

	// cout << s.isScramble("great", "rgeat") << endl;
	// cout << s.isScramble("abc", "bac") << endl;
	// cout << s.isScramble("abc", "cba") << endl;
	// cout << s.isScramble("abab", "aabb") << endl;
	cout << s.isScramble("cbccbcbcacaaaaaacabaabcaaacaccbc", "cabaabcaaacaccbccabaabcaaacaccbc") << endl;

	return 0;
}