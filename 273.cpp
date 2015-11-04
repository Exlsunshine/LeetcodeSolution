#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        std::vector<string> units = {"","Thousand","Million","Billion","Trillion"};

        std::vector<string> digits = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                      "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        std::vector<string> decades = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string ans;
        int cnt = 0;
        while (num > 0)
        {
            if (num % 1000 != 0)
                ans = getNumToString(num % 1000, digits, decades) + " " + units[cnt] + " " + ans;
            num /= 1000;
            cnt++;
        }

        int i, j;
        for (i = 0; i < ans.length(); ++i)
        {
            if (ans[i] != ' ')
                break;
        }

        for (j = ans.length() - 1; j >= 0; j--)
        {
            if (ans[j] != ' ')
                break;
        }

        return ans.substr(i, j - i + 1);
    }

private:
    // 0 <= num <= 999
    string getNumToString(int num, const std::vector<string> &digits, const std::vector<string> &decades)
    {
        int cnt = 1;
        int temp = num / 10;

        while (temp != 0)
        {
            cnt++;
            temp /= 10;
        }

        string ans;
        if (cnt == 3)
        {
            ans = digits[num / 100] + " Hundred";
            cnt--;
            num = num % 100;
            
            if (num == 0)
                return ans;
            else
                ans = ans + " ";
        }

            if (num < 20)
                ans = ans + digits[num] + "";
            else
            {
                ans = ans + decades[num / 10] + "";
                if (num % 10 != 0)
                    ans = ans + " " + digits[num % 10] + "";
            }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.numberToWords(1000010) << "==" << endl;
    return 0;
}