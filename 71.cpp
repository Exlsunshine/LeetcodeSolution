#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        stack<string> stk;
        string name;

        path.push_back('/');
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
            {
                if (name == "")
                    ;
                else if (name == ".")
                    ;
                else if (name == "..")
                {
                    if (!stk.empty())
                        stk.pop();
                }
                else
                    stk.push(name);
                name.clear();
            }
            else
                name.push_back(path[i]);
        }

        string ans;
        while (!stk.empty())
        {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }

        return ans == "" ? "/" : ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.simplifyPath("/../");
	return 0;
}