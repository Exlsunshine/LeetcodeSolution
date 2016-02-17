#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points)
    {
    	int maxLength = 0;
    	for (int i = 0; i < points.size(); ++i)
    	{
    		std::vector<double> slops;
    		int same = 0;
    		int vertical = 0;

    		for (int j = 0; j < points.size(); ++j)
    		{
    			if (points[i].x == points[j].x && points[i].y == points[j].y)
    				same++;
    			else if (points[i].x == points[j].x)
    				vertical++;
				else
    			{
    				double slop = (points[j].y - points[i].y) * 1.0 / (points[j].x - points[i].x);
    				slops.push_back(slop);
    			}
    		}
    		
    		sort(slops.begin(), slops.end());
    		
    		// normal points
    		int currentMax = 0;
    		int strike = slops.size() > 0 ? 1 : 0;
    		for (int i = 1; i < slops.size(); ++i)
    		{
    			if (slops[i] == slops[i - 1])
    				strike++;
    			else
    			{
    				currentMax = max(currentMax, strike);
    				strike = 1;
    			}
    		}
    		currentMax = max(currentMax, strike);
    		
    		// vertical points
    		currentMax = max(currentMax, vertical) + same;

            // max
    		maxLength = max(maxLength, currentMax);
    	}

    	return maxLength;
    }
};

int main(int argc, char const *argv[])
{
	return 0;
}