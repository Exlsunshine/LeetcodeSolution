#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) 
    {
    	int cnt = 0;

    	for (int i = 1; i <= n; i *= 10)
    	{
    		int front = n / i;
    		int rear = n % i;
    		int digit = front % 10;

    		if (digit == 1)
    			cnt += front / 10 * i + (rear + 1);
    		else if (digit == 0)
    			cnt += front / 10 * i;
    		else
    			cnt += (front / 10 + 1) * i;
    	}    

    	return cnt;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.countDigitOne(13) << endl;
	return 0;
}
