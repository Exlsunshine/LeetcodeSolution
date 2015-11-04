#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s)
    {
        stack<int> singed;
        int ans = 0;
        int sign = 1;
        int currentNum = 0;

        singed.push(1);
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
                currentNum = currentNum * 10 + s[i] - '0';
            else if (s[i] == '+' || s[i] == '-')
            {
                ans = ans + currentNum * sign * singed.top();
                sign = (s[i] == '+' ? 1 : -1);
                currentNum = 0;
            }
            else if (s[i] == '(')
            {
                singed.push(sign * singed.top());
                sign = 1;
            }
            else if (s[i] == ')')
            {
                ans = ans + currentNum * sign * singed.top();
                singed.pop();
                currentNum = 0;
               // sign = 1;
            }
            else
                continue;
        }

        if (currentNum != 0)
            ans = ans + currentNum * sign;// * singed.top();

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.calculate("1-(((34-2)+5)-7)-4+234-(7-6+2(2-(((0-4)+3))+3-6)-20)");
    return 0;
}