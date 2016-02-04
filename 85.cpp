#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
            
    	int m = matrix.size();
    	int n = matrix[0].size();
    	std::vector<int> heights(n, 0);
    	int maxArea = 0;

		
		for (int i = 0; i < m; ++i)
    	{
    		for (int j = 0; j < n; ++j)
    		{
    			if (matrix[i][j] == '1')
    				heights[j] += 1;
    			else
    				heights[j] = 0;
    		}

    		stack<int> stk;
    		int j = 0;
    		while (j < n)
    		{
    			if (stk.empty() || heights[stk.top()] <= heights[j])
    				stk.push(j++);
    			else
    			{
    				int index = stk.top();
    				stk.pop();
					maxArea = max(maxArea, heights[index] * (stk.empty() ? j : (j - stk.top() - 1)));
    			}
    		}

    		j = n - 1;
    		while (!stk.empty())
    		{
    			int index = stk.top();
    			stk.pop();

    			maxArea = max(maxArea, heights[index] * (stk.empty() ? j + 1: j - stk.top()));
    		}
    	}    	

    	return maxArea;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector< std::vector<char> > v(1, std::vector<char>(1, 'A'));
	cout << s.maximalRectangle(v);
	return 0;
}