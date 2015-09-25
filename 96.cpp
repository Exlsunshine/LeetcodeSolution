#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n)
    {
    	int *d = new int[n + 1];
    	memset(d, 0, sizeof(int) * (n + 1));

    	d[0] = 1;
    	d[1] = 1;
    	for (int i = 2; i <= n; ++i)
    	{
    		for (int j = 0; j < i / 2; ++j)
    			d[i] += d[j] * d[(i - 1 ) - j];

    		d[i] *= 2;
    		
    		if (i % 2 == 1)
    			d[i] += d[i / 2] * d[i / 2];
    	}

    	cout << d[n] << endl;
    	return d[n];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	s.numTrees(4);
	return 0;
}