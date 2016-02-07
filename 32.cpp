#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s)
	{
		stack<int> stk;

		int maxLength = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(')
			{
				stk.push(0);
				continue;
			}

			if (!stk.empty())
			{
				int v = stk.top();
				stk.pop();

				// matching a '('
				if (v == 0)
				{
					v += 2;
					while (!stk.empty() && stk.top() != 0)
					{
						v += stk.top();
						stk.pop();
					}
					maxLength = max(maxLength, v);
					stk.push(v);
				}
				else
				{
					if (!stk.empty())
					{
						v += 2;
						stk.pop();

						while (!stk.empty() && stk.top() != 0)
						{
							v += stk.top();
							stk.pop();
						}

						stk.push(v);
					}

					maxLength = max(maxLength, v);
				}
			}
		}

		return maxLength;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.longestValidParentheses("(()");
	return 0;
}