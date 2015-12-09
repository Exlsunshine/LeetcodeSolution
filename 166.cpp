#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
    	if (numerator == 0)
    		return "0";

    	long numer = ((long) numerator > 0 ? numerator : -1 * (long) numerator);
    	long denom = ((long) denominator > 0 ? denominator : -1 * (long) denominator);
    	string decimal;

    	// Add minus sign if it's necessary.
		if (((numerator < 0) ^ (denominator < 0)) == 1)
			decimal = "-";

		// Decide integral part.
		long quotient = numer / denom;
		decimal += to_string(quotient);

		// decimal part
		long reminder = numer % denom;
		if (reminder == 0)
			return decimal;
		decimal += ".";

		unordered_map<long, long> reminderHistory;
		long index = decimal.length();
		for (;;)
		{
			unordered_map<long, long>::iterator it = reminderHistory.find(reminder);
			if (it != reminderHistory.end())
			{
				decimal.insert(it->second, "(");
				decimal.append(")");
				break;
			}

			reminderHistory.insert(make_pair(reminder, index++));
			reminder *= 10;
			decimal += to_string(reminder / denom);
			reminder = reminder % denom;

			if (reminder == 0)
				break;
		}

		return decimal;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.fractionToDecimal(22, 3);
	return 0;
}