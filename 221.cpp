#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int **dp = new int*[m + 1];
        for (int i = 0; i < m + 1; ++i)
        {
            dp[i] = new int[n + 1];
            memset(dp[i], 0, sizeof(int) * (n + 1));
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
                dp[i][j] = matrix[i - 1][j - 1] - '0';
        }


        int maxRadis = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i - 1][j - 1] == '0')
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    maxRadis = max(dp[i][j], maxRadis);
                }
            }
        }

        return maxRadis * maxRadis;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::vector<char>> matrix;
    vector<char> v = {'1', '0', '1', '0', '0'};
    matrix.push_back(v);
    vector<char> v2 = {'1', '0', '1', '1', '1'};
    matrix.push_back(v2);
    vector<char> v3 = {'1', '1', '1', '1', '1'};
    matrix.push_back(v3);
    vector<char> v4 = {'1', '0', '0', '1', '0'};
    matrix.push_back(v4);
    cout << s.maximalSquare(matrix);
    return 0;
}