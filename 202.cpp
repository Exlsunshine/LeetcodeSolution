#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
	bool isHappy(int n) 
    {
    	int slow = getSqrtNum(n);
    	int fast = getSqrtNum(getSqrtNum(n));
    	cout << "Slow is " << slow << "Fast is " << fast << endl;

    	while (slow != fast)
    	{
    		slow = getSqrtNum(slow);
    		fast = getSqrtNum(getSqrtNum(fast));
    		cout << "Slow is " << slow << "Fast is " << fast << endl;

    		if (slow == 1 || fast == 1)
    			return true;
    	}

    	if (getSqrtNum(slow) == 1)
    		return true;
    	else
   			return false;
    }

private:
	int getSqrtNum(int n)
	{
		//if (n % 10 == 0)
		//	return 1;

		int cnt = 0;
		
		while (n >= 10)
		{
			cnt += pow(n % 10, 2);
			n /= 10;
		}

		cnt += pow(n, 2);

		return cnt;
	}
};

int main()
{
	Solution s;
	cout << s.isHappy(7);
	cin.get();
	return 0;
}