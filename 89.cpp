#include <iostream>
#include <vector>

using namespace std;

/*
grayCode(n):
for (i : 0 -> 2 ^ n)
	i = (i >> 1) ^ i;
This is the very defination of gray code generation.

grayCode2Binary(x)
	mask = x -> 1;
	for (mask != 0)
		x = x ~ mask;
		mask = mask >> 1;
*/
class Solution {
public:
    vector<int> grayCode(int n) 
    {
        std::vector<int> v;
        int code = 0;
        
        if (n == 0)
            v.push_back(0);
        else
            backtracking(1, code, n, v);

       	return v;
    }

private:
	void backtracking(int level, int &code, int n, std::vector<int> &codes)
	{
		if (level > n)
			return;
		else if (level == n)
		{
			codes.push_back(code);
			code = code ^ 1;
			codes.push_back(code);
			return;
		}

		backtracking(level + 1, code, n, codes);
		int mask = 1 << (n - level);
		code = mask ^ code;
		backtracking(level + 1, code, n, codes);
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	s.grayCode(3);
	return 0;
}