#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) 
    {
    	std::vector<string> ans;
    	std::vector<string> v;

    	splitIP(0, 4, s, ans, v);

    	return ans;
    }

private:
	void splitIP(int startIndex, int segments, string &str, std::vector<string> &ans, std::vector<string> &ip)
	{
		//cout << startIndex << "\t" << segments << endl;

		if (startIndex >= str.length() && segments != 0)
			return;
		if (startIndex != str.length() && segments == 0)
			return;
		if (startIndex == str.length() && segments == 0)
		{
			ans.push_back(ip[0] + '.' + ip[1] + '.' + ip[2] + '.' + ip[3]);
			return;
		}

		for (int i = startIndex; i < startIndex + 3 && i < str.length(); ++i)
		{
			string digit = str.substr(startIndex, i - startIndex + 1);

			if (stoi(digit) > 255)
				return;

			ip.push_back(digit);
			splitIP(i + 1, segments - 1, str, ans, ip);
			ip.pop_back();

			if (str[startIndex] == '0')
				return;
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str = "010010";
	std::vector<string> v = s.restoreIpAddresses(str);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	return 0;
}