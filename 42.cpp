#include <iostream>
#include <vector>

using namespace std;

/*
	Time complexity: O(n^2);
*/
class Solution {
public:
    int trap(vector<int>& height)
    {
    	int front = 0, rear = height.size() - 1;
    	std::vector<int> traffic(height.size(), 0);

    	while (front < rear)
    	{
    		if (height[front] == 0)
    			front++;
    		else if (height[rear] == 0)
    			rear--;
    		else
    		{
    			int small = min(height[front], height[rear]);

    			for (int i = front + 1; i < rear; ++i)
    				traffic[i] = max(traffic[i], small - height[i]);

    			if (height[front] < height[rear])
    				front++;
    			else if (height[front] > height[rear])
    				rear--;
    			else
    			{
    				front++;
    				rear--;
    			}
    		}
    	}

    	int water = 0;
    	for (int i = 0; i < traffic.size(); ++i)
    		water += traffic[i];

    	return water;
    }
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution s;
	cout << endl;
	cout << s.trap(v);
	return 0;
}