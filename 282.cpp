#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target)
    {
    	std::vector<string> ans;
    	backtracking(0, ans, "", 0, 0, num, target);

    // 	for (int i = 0; i < ans.size(); ++i)
    // 		cout << ans[i] << endl;

    	return ans;
    }

private:
	void backtracking(int index, std::vector<string> &ans, string equitation, long value, long multiply,
		const string &num, const int &target)
	{
		if (index == num.size())
		{
			if (value == target)
				ans.push_back(equitation);
			return;
		}

		for (int i = 1; index + i - 1 < num.size(); ++i)
		{
			long currentNumber = atol(num.substr(index, i).c_str());

			if (index == 0)
				backtracking(index + i, ans, to_string(currentNumber), currentNumber, currentNumber, num, target);
			else
			{
			    backtracking(index + i, ans, equitation + "*" + to_string(currentNumber), value - multiply + currentNumber * multiply, currentNumber * multiply, num, target);
				backtracking(index + i, ans, equitation + "+" + to_string(currentNumber), value + currentNumber, currentNumber, num, target);
				backtracking(index + i, ans, equitation + "-" + to_string(currentNumber), value - currentNumber, -currentNumber, num, target);
			}
			
			if (currentNumber == 0)
				break;
		}
	}
};
/*	TLE
class Solution {
public:
    vector<string> addOperators(string num, int target)
    {
    	std::vector<string> ans;
    	std::vector<char> operators;
    	backtracking(num, target, 0, ans, operators);

    	for (int i = 0; i < ans.size(); ++i)
    	{
    		cout << ans[i] << endl;
    	}
    	return ans;
    }

private:
	void backtracking(const string &num, const int &target, int index, std::vector<string> &ans, std::vector<char> &operators)
	{
		if (index == num.length() - 1)
		{
			checkValidation(num, target, operators, ans);
			return ;
		}

		std::vector<char> opts = {'+', '-', '*', ' '};
		for (int i = 0; i < opts.size(); ++i)
		{
			if (i == 3 && num[index] == '0')
				break;

			operators.push_back(opts[i]);
			backtracking(num, target, index + 1, ans, operators);
			operators.pop_back();
		}
	}

	void checkValidation(const string &num, const int &target, std::vector<char> &operators, std::vector<string> &ans)
	{
		string str;
		for (int i = 0; i < num.size() - 1; ++i)
		{
			if (operators[i] == ' ')
				str = str + num[i];
			else
				str = str + num[i] + operators[i];
		}
		str = str + num[num.size() - 1];

		std::vector<long long> operands;

		// cout << str << endl;

		long long value;
		bool shouldMultiply = false;
		int minus = 1;
		long long d = 0;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				d = d * 10 + (str[i] - '0');
				if (i == str.length() - 1)
				{
					operands.push_back(d * minus);

					if (shouldMultiply)
						operands.back() = operands.back() * value;
				}
			}
			else
			{
				operands.push_back(minus * d);
				minus = (str[i] == '-') ? -1 : 1;
				d = 0;

				if (shouldMultiply)
				{
					shouldMultiply = false;
					operands.back() = operands.back() * value;
				}

				if (str[i] == '*')
				{
					shouldMultiply = true;
					value = operands.back();
					operands.pop_back();
				}
			}
		}

		while (operands.size() > 1)
		{
			long long second = operands.back();
			operands.pop_back();
			long long first = operands.back();
			operands.pop_back();
			operands.push_back(first + second);
		}

		if (operands.back() == target)
			ans.push_back(str);
	}
};
*/

int main(int argc, char const *argv[])
{
	Solution s;
	s.addOperators("105", 5);

	return 0;
}