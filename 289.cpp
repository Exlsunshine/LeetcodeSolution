#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int rows = board.size();
        int cols = board[0].size();
        int current_mask = 0x01;
        int next_mask = 0x02;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int cnt = 0;

                for (int p = -1; p <= 1; ++p)
                {
                    if (i + p >= 0 && i + p < rows)
                    {
                        for (int q = -1; q <= 1; ++q)
                        {
                            if (j + q >= 0 && j + q < cols)
                            {
                                if (p == q && q == 0)
                                    continue;
                                else
                                {
                                    if ((board[i + p][j + q] & current_mask) == 1)
                                        cnt++;
                                }
                            }
                        }
                    }
                }
                
                //cout << "(" << i << "," << j << ")" << "=" << cnt << endl;

                if ((board[i][j] & current_mask) == 1)
                {
                    if (cnt < 2 || cnt > 3)
                        board[i][j] = 0x01;
                    else
                        board[i][j] = 0x03;
                }
                else
                {
                    if (cnt == 3)
                        board[i][j] = 0x02;
                    else
                        board[i][j] = 0x00;
                }
            }
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
                board[i][j] = board[i][j] >> 1;
        }
    }
};

int main()
{
	Solution s;

	return 0;
}














