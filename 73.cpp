#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) 
    {
    	int m = matrix.size();
    	int n = matrix[0].size();
    	bool original_row = false;

    	for (int i = 0; i < m; ++i)
    	{
    		if (matrix[i][0] == 0)
    			original_row = true;
    			
    		for (int j = 1; j < n; j++)
    		{
    			if (matrix[i][j] == 0)
    			{
    				matrix[i][0] = 0;
    				matrix[0][j] = 0;
    			}
    		}
    	}
    	
    	for (int i = m - 1; i >= 0; --i)
    	{
    		for (int j = n - 1; j > 0; --j)
    		{
    			if (matrix[i][0] == 0 || matrix[0][j] == 0)
    				matrix[i][j] = 0;
    		}
    		
    		if (original_row == true)
    		    matrix[i][0] = 0;
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector< std::vector<int> > v;

	std::vector<int> r1 = {1, 2, 3, 1};
	std::vector<int> r2 = {0, 2, 3, 1};
	std::vector<int> r3 = {1, 2, 3, 0};
	v.push_back(r1);
	v.push_back(r2);
	v.push_back(r3);


	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
    cout << "======" << endl;

	s.setZeroes(v);

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}














