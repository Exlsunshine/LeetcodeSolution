#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int *d = new int[1 + citations.size()];
        memset(d, 0, sizeof(int) * (1 + citations.size()));

        for (int i = 0; i < citations.size(); ++i)
        {
            int idx = citations[i] > citations.size() ? citations.size() : citations[i];
            d[idx]++;
        }

        int cnt = 0;
        for (int i = citations.size(); i >= 0; --i)
        {
            cnt += d[i];
            if (cnt >= i)
                return i;
        }

        return -1;
    }
};

/*
class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int min = INT_MAX;
        int *d = new int[1 + citations.size()];
        int last = -1;
        memset(d, 0, sizeof(int) * (1 + citations.size()));

        for (int i = 1; i <= citations.size(); ++i)
        {
            if (citations[i - 1] <= d[i - 1])
                d[i] = d[i - 1];
            else if (citations[i - 1] > d[i - 1] && citations[i - 1] <= min)
            {
                d[i] = d[i - 1] + 1;
                min = citations[i - 1];
            }
            else if (citations[i - 1] > d[i - 1] && citations[i - 1] > min)
            {
                if ((i == d[i - 1] + 1) && (min < d[i - 1] + 1))
                {
                    if (last > 0)
                    {
                        d[i] = d[i - 1] + 1;
                        min = last <= citations[i - 1] ? last : citations[i - 1];
                        last = -1;
                    }
                    else
                    {
                        last = citations[i - 1];
                        d[i] = d[i - 1];
                    }
                }
                else
                    d[i] = d[i - 1] + 1;
            }
        }

        for (int i = 1; i <= citations.size(); ++i)
        {
            cout << d[i] << " ";
        }

        return d[citations.size()];
    }
};
*/

int main()
{
	Solution s;
    std::vector<int> v = {1,1,2,1};//{4,0,6,1,5, 7};

    cout << s.hIndex(v) << endl;
	return 0;
}














