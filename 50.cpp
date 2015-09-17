#include <iostream>

using namespace std;

class Solution 
{
public:
    double myPow(double x, int n) 
    {
    	int exps = 0;

    	while ()
    	{
	    	int exponential = 1;
	    	int cnt = 0;
	    	while ((exponential << 1) < n)
	    	{
	    		exponential <<= 1;
	    		cnt++;
	    	}
	    	exps += cnt;
	    	n -= exponential;
	    }

	    return x << 
    }
};