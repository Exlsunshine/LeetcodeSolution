#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        if (citations.size() == 0)
            return 0;
            
        int low = 0, high = citations.size() - 1;
        int current_h = 0;

        while (low <= high)
        {
            int mid = (low + high ) / 2;

            if (citations[mid] >= (citations.size() - mid))
            {
                if ((int)citations.size() - mid >= current_h)
                    current_h = (citations.size() - mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return current_h;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {0,1,3,4,5,6,7};
    cout << s.hIndex(v);
    return 0;
}