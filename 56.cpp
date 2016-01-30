#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        if (intervals.size() <= 1)
            return intervals;

        std::vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), compareInterval());

        Interval small = intervals[0];
        for (int i = 1; i < intervals.size(); ++i)
        {
            Interval large = intervals[i];

            //  small: ########
            //  large:           ####
            // or
            //  small: ########
            //  large:         ####
            if (small.end < large.start)
            {
                ans.push_back(Interval(small.start, small.end));
                small = large;
            }
            else
                small.end = max(small.end, large.end);
            //  small: ########
            //  large:        ####
            // or
            //  small: ########
            //  large:    ####
        }
        ans.push_back(Interval(small.start, small.end));

        return ans;
    }

private:
    struct compareInterval
    {
        inline bool operator()(const Interval &i1, const Interval &i2)
        {
            if (i1.start < i2.start)
                return true;
            else if (i1.start == i2.start)
                return (i1.end < i2.end);
            else
                return false;
        }
    };
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<Interval> v(17);
    /*
    v[0] = Interval(1, 3);
    v[1] = Interval(2, 6);
    v[2] = Interval(8, 10);
    v[3] = Interval(15, 18);
    */

    v[0] = Interval(890,2110);
    v[1] = Interval(880,2120);
    v[2] = Interval(870,2130);
    v[3] = Interval(860,2140);
    v[4] = Interval(130,2870);
    v[5] = Interval(120,2880);
    v[6] = Interval(110,2890);
    v[7] = Interval(100,2900);
    v[8] = Interval(90,2910);
    v[9] = Interval(80,2920);
    v[10] = Interval(70,2930);
    v[11] = Interval(60,2940);
    v[12] = Interval(50,2950);
    v[13] = Interval(40,2960);
    v[14] = Interval(30,2970);
    v[15] = Interval(20,2980);
    v[16] = Interval(10,2990);

    s.merge(v);

	return 0;
}







