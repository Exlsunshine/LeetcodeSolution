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
    vector<string> diffWaysToCompute(string input)
    {
        return devideAndConquqer(0, input.length() - 1, input);
    }

private:
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

    std::vector<string> devideAndConquqer(int start, int end, string &str)
    {
        int index = -1;
        int optNums = checkOpts(str, start, end, index);
        if (0 == optNums)
            return std::vector<string>(1, str.substr(start, end - start + 1));
        else if (1 == optNums)
            return std::vector<string>(1, "(" + str.substr(start, end - start + 1) + ")");

        std::vector<string> ans;
        for (int i = start; i <= end; ++i)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*')
            {
                std::vector<string> v1 = devideAndConquqer(start, i - 1, str);
                std::vector<string> v2 = devideAndConquqer(i + 1, end, str);

                for (int m = 0; m < v1.size(); ++m)
                    for (int n = 0; n < v2.size(); ++n)
                        ans.push_back(v1[m] + str[i] + v2[n]);
            }
        }

        return ans;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<string> v = s.diffWaysToCompute("2*3*4");//"2*3-4*5");

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
    return 0;
}