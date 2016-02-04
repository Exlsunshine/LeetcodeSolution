#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
		if (heights.size() == 0)
			return 0;

    	stack<int> stk;
    	int largest = 0;

    	for (int i = 0; i < heights.size(); ++i)
    	{
    		cout << i << endl;
    		if (stk.empty() || heights[stk.top()] <= heights[i])
    			stk.push(i);
    		else
    		{
    			while (!stk.empty() && heights[stk.top()] > heights[i])
    			{
	    			int index = stk.top();
	    			stk.pop();
	    			if (!stk.empty())
		    			largest = max(largest, heights[index] * (i - stk.top() - 1));
		    		else
		    			largest = max(largest, heights[index] * (i - index));
    			}
    			stk.push(i);
    		}
    	}

    	int lastIndex = stk.top();
    	stk.pop();
    	largest = max(largest, heights[lastIndex]);

    	while (!stk.empty())
    	{
    		int index = stk.top();
    		stk.pop();
    		if (!stk.empty())
    			largest = max(largest, heights[index] * (lastIndex - stk.top()));
    		else
    			largest = max(largest, heights[index] * (lastIndex - index));
    	}

    	return largest;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v = {6,2,5,4,5,2,6};
	cout << s.largestRectangleArea(v);
	return 0;
}