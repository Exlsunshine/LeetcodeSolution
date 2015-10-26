#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) 
    {
    	int small = 0, mid = 0, large = 0;
    	std::vector<int> v(n, 0);
    	v[0] = 1;

    	for (int i = 1; i < n; ++i)
    	{
    		v[i] = min(v[small] * 5, min(v[mid] * 3, v[large] * 2));

    		if (v[i] == v[small] * 5)
    			small++;
    		if (v[i] == v[mid] * 3)
    			mid++;
    		if (v[i] == v[large] * 2)
    			large++;
    	}

    	return v[n - 1];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.nthUglyNumber(11) << endl;
	return 0;
}