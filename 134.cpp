#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	// If gas i can not reach to gas j(suppose j is the first sation that i cannot reach to ), 
	// then all gas stations between i and j cannot reach to j neigher. 
	// Because if there is a way to j from any station between (i,j),
	// then we can reach to that station first and then get to j.
	// So we can directly jump to j + 1 station to start over instead of i += 1.
	// This make time complecity down to O(n) from O(n^2)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
    	int i = 0, j;
    	while (i < gas.size())
    	{
    		int remain = 0;
    		for (j = 0; j < gas.size(); ++j)
    		{
    			int k = (i + j) % gas.size();
    			remain += gas[k] - cost[k];
    			if (remain < 0)
    				break;
    		}

    		if (j == gas.size())
    			return i;
    		else
    			i += j + 1;
    	}

    	return -1;
    }
};

int main()
{
	return 0;
}