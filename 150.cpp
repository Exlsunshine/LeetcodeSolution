#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
    	stack<int> stk;

    	int tokenLength = tokens.size();

    	for (int i = 0; i < tokenLength; ++i)
    	{
    		if (tokens[i] == "+")
    		{
    			int opt1 = stk.top();
    			stk.pop();
    			int opt2 = stk.top();
    			stk.pop();
    			stk.push(opt2 + opt1);
    		}
    		else if (tokens[i] == "-")
    		{
    			int opt1 = stk.top();
    			stk.pop();
    			int opt2 = stk.top();
    			stk.pop();
    			stk.push(opt2 - opt1);	
    		}
    		else if (tokens[i] == "*")
    		{
    			
    			int opt1 = stk.top();
    			stk.pop();
    			int opt2 = stk.top();
    			stk.pop();
    			stk.push(opt2 * opt1);
    		}
    		else if (tokens[i] == "/")
    		{
    			
    			int opt1 = stk.top();
    			stk.pop();
    			int opt2 = stk.top();
    			stk.pop();
    			stk.push(opt2 / opt1);
    		}
    		else
    			stk.push(stoi(tokens[i]));
    	}

    	int ans = stk.top();
    	stk.pop();
    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<string> v = {"4", "13", "5", "/", "+"};
	cout << s.evalRPN(v);
	return 0;
}