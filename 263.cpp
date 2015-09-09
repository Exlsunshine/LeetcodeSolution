#include <iostream>
#include <cmath>
using namespace std;

class Solution 
{
public:
    bool isUgly(int num) 
    {
        if (num <= 0)
        	return false;
        if (num == 1)
        	return true;

		for (int i = 5; i > 1; i--)
		{
			while (num % i == 0)
				num /= i;
		}

		return num == 1;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.isUgly(2147483648) << endl;

	return 0;
}