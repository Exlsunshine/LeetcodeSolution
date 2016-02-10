#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
    	if (leftHalf.size() == righHalf.size())
    	{
    		if (leftHalf.size() == 0 || num <= leftHalf.top())
    			leftHalf.push(num);
    		else
    			righHalf.push(num);
    	}
    	else
    	{
    		if (leftHalf.size() < righHalf.size())
    		{
    			if (num <= leftHalf.top())
    				leftHalf.push(num);
    			else
    			{
    				righHalf.push(num);
    				leftHalf.push(righHalf.top());
    				righHalf.pop();
    			}
    		}
    		else
    		{
    			if (num <= leftHalf.top())
    			{
    				leftHalf.push(num);
    				righHalf.push(leftHalf.top());
    				leftHalf.pop();
    			}
    			else
    				righHalf.push(num);
    		}
    	}
    }

    // Returns the median of current data stream
    double findMedian()
    {
    	if ((leftHalf.size() + righHalf.size()) % 2 == 0)
    		return (leftHalf.top() + righHalf.top()) / 2.0;
    	else
    		return (leftHalf.size() > righHalf.size() ? leftHalf.top() : righHalf.top());
    }

    
private:
	priority_queue< int, std::vector<int>, less<int> > leftHalf;
	priority_queue< int, std::vector<int>, greater<int> > righHalf;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

/*	Little bit slow because the addNum operation might push or pop about 3 - 5 times. average for 4 times per operation.
class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        leftHalf.push(num);
        rightHalf.push(leftHalf.top());
        leftHalf.pop();
        
        if (leftHalf.size() < rightHalf.size())
        {
            leftHalf.push(rightHalf.top());
            rightHalf.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
    	if ((leftHalf.size() + rightHalf.size()) % 2 == 0)
    		return (leftHalf.top() + rightHalf.top()) / 2.0;
    	else
    		return (leftHalf.size() > rightHalf.size() ? leftHalf.top() : rightHalf.top());
    }

    
private:
	priority_queue< int, std::vector<int>, less<int> > leftHalf;
	priority_queue< int, std::vector<int>, greater<int> > rightHalf;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
*/

int main(int argc, char const *argv[])
{
	MedianFinder m;

	m.addNum(12);
	cout << m.findMedian() << " ";
	m.addNum(10);
	cout << m.findMedian() << " ";
	m.addNum(13);
	cout << m.findMedian() << " ";
	m.addNum(11);
	cout << m.findMedian() << " ";
	m.addNum(5);
	cout << m.findMedian() << " ";
	m.addNum(15);
	cout << m.findMedian() << " ";
	m.addNum(1);
	cout << m.findMedian() << " ";
	m.addNum(11);
	cout << m.findMedian() << " ";
	m.addNum(6);
	cout << m.findMedian() << " ";
	m.addNum(17);
	cout << m.findMedian() << " ";
	m.addNum(14);
	cout << m.findMedian() << " ";
	m.addNum(8);
	cout << m.findMedian() << " ";
	m.addNum(17);
	cout << m.findMedian() << " ";
	m.addNum(6);
	cout << m.findMedian() << " ";
	m.addNum(4);
	cout << m.findMedian() << " ";
	m.addNum(16);
	cout << m.findMedian() << " ";
	m.addNum(8);
	cout << m.findMedian() << " ";
	m.addNum(10);
	cout << m.findMedian() << " ";
	m.addNum(2);
	cout << m.findMedian() << " ";
	m.addNum(12);
	cout << m.findMedian() << " ";
	m.addNum(0);
	cout << m.findMedian() << " ";

	return 0;
}