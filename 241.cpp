#include <iostream>
#include <vector>

using namespace std;


void print(std::vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

class Solution {
public:
    vector<int> diffWaysToCompute(string input)
    {
        return devideAndConquqer(0, input.length() - 1, input);
    }

private:
    int calc(char opt, int i, int j)
    {
        int val;
        switch(opt)
        {
            case '+':
                val = i + j;
                break;
            case '-':
                val = i - j;
                break;
            case '*':
                val = i * j;
                break;
        }

        return val;
    }

    int checkOpts(string &str, int start, int end, int &index)
    {
        int k = 0;
        for (int i = start; i <= end; ++i)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*')
            {
                index = i;
                k++;
            }
            if (k >= 2)
                break;
        }

        return k;
    }

    int getNum(string &str, int start, int end)
    {
        int val = 0;

        for (int i = start; i <= end; ++i)
            val = val * 10 + str[i] - '0';

        return val;
    }

    std::vector<int> devideAndConquqer(int start, int end, string &str)
    {
        int index = -1;
        int optNums = checkOpts(str, start, end, index);
        if (0 == optNums)
            return std::vector<int>(1, getNum(str, start, end));
        else if (1 == optNums)
            return std::vector<int>(1, calc(str[index], getNum(str, start, index - 1), getNum(str, index + 1, end)));

        std::vector<int> ans;
        for (int i = start; i <= end; ++i)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*')
            {
                std::vector<int> v1 = devideAndConquqer(start, i - 1, str);
                std::vector<int> v2 = devideAndConquqer(i + 1, end, str);

                for (int m = 0; m < v1.size(); ++m)
                    for (int n = 0; n < v2.size(); ++n)
                        ans.push_back(calc(str[i], v1[m], v2[n]));
            }
        }

        return ans;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = s.diffWaysToCompute("2*3+4*5");//"2*3-4*5");

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
    return 0;
}