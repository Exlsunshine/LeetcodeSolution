#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
    	long numer = (numerator > 0 ? numerator : -1 * numerator);
    	long denom = (denominator > 0 ? denominator : -1 * denominator);
    	string decimal;

		if ((numerator < 0) ^ (denominator < 0) == 1)
			decimal = "-";

		// integral part.
		long quotient = numer / denom;
		decimal += to_string(quotient);

		// decimal part
		long reminder = numer % denom;
		if (reminder == 0)
			return decimal;
		else
			decimal += ".";
    }
};

int main(int argc, char const *argv[])
{
	cout << 3 % 5 << endl;
	return 0;
}