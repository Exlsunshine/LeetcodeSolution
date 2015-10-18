#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        std::vector<std::vector<string>> dictionary;
        std::vector<string> v0 = {" "};
        std::vector<string> v1 = {""};
        std::vector<string> v2 = {"a", "b", "c"};
        std::vector<string> v3 = {"d", "e", "f"};
        std::vector<string> v4 = {"g", "h", "i"};
        std::vector<string> v5 = {"j", "k", "l"};
        std::vector<string> v6 = {"m", "n", "o"};
        std::vector<string> v7 = {"p", "q", "r", "s"};
        std::vector<string> v8 = {"t", "u", "v"};
        std::vector<string> v9 = {"w", "x", "y", "z"};
        dictionary.push_back(v0);
        dictionary.push_back(v1);
        dictionary.push_back(v2);
        dictionary.push_back(v3);
        dictionary.push_back(v4);
        dictionary.push_back(v5);
        dictionary.push_back(v6);
        dictionary.push_back(v7);
        dictionary.push_back(v8);
        dictionary.push_back(v9);

        string str(digits.size(), ' ');
        std::vector<string> ans;

        if (digits.size() == 0)
            return ans;
        
        backTracking(0, ans, str, dictionary, digits);

        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl;

        return ans;
    }
private:
    void backTracking(int stringIndex, std::vector<string> &ans, string &str,
        const std::vector<std::vector<string>> &dictionary, const string &digits)
    {
        if (stringIndex == digits.size())
        {
            ans.push_back(str);
            return;
        }

        for (int i = 0; i < dictionary[digits[stringIndex] - '0'].size(); ++i)
        {
            str[stringIndex] = dictionary[digits[stringIndex] - '0'][i][0];
            backTracking(stringIndex + 1, ans, str, dictionary, digits);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution  s;
    s.letterCombinations("23");
	return 0;
}