#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
    	std::vector<Interval> ans;
    	int i = 0;

    	while (i < intervals.size() && intervals[i].end < newInterval.start)
    	{
    		ans.push_back(intervals[i]);
    		i++;
    	}

    	if (i < intervals.size())
    	{
    		if (intervals[i].start > newInterval.end)
    			ans.push_back(intervals);
    		else
    		{
    			int s = min(intervals[i].start, newInterval.start);
    			int e = max(intervals[i].end, newInterval.end);

    			i += 1;
    			while (i < intervals.size() && e >= intervals[i].start)
    			{
    				e = max(e, intervals[i].end);
    				i++;
    			}
    			ans.push_back(Interval(s, e));
    		}
    	}
    	else
    		ans.push_back(newInterval);

    	while (i < intervals.size())
    	{
    		ans.push_back(intervals[i]);
    		i++;
    	}


    	return ans;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}