#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
    	std::vector<set<int>> children(numCourses, set<int>());
    	std::vector<set<int>> parents(numCourses, set<int>());
    	std::vector<int> indegree(numCourses, 0);
    	std::vector<bool> visited(numCourses, false);
    	stack<int> q;
    	int totalVisitedCount = 0;

    	for (int i = 0; i < prerequisites.size(); ++i)
    	{
    		children[prerequisites[i].second].insert(prerequisites[i].first);
    		parents[prerequisites[i].first].insert(prerequisites[i].second);
    		indegree[prerequisites[i].first]++;
    	}
    	
    	for (int i = 0; i < indegree.size(); ++i)
    	{
    		if (indegree[i] == 0)
    			q.push(i);
    	}

    	while (!q.empty())
    	{
    		int root = q.top();
    		q.pop();

    		visited[root] = true;
    		totalVisitedCount++;

    		for (set<int>::iterator i = children[root].begin(); i != children[root].end(); ++i)
    		{
    			if (!visited[*i])
    			{
    				bool parentsAllVisited = true;
	    			for (set<int>::iterator k = parents[*i].begin(); k != parents[*i].end(); ++k)
	    			{
	    				if (visited[*k] == false)
	    				{
	    					parentsAllVisited = false;
	    					break;
	    				}
	    			}

	    			if (parentsAllVisited)
	    				q.push(*i);
    			}
    		}
    	}

    	return totalVisitedCount == numCourses;
    }
};

int main(int argc, char const *argv[])
{
	std::vector<pair<int, int>> v;
	/*	
	v.push_back(make_pair(1,0));
	v.push_back(make_pair(2,0));
	v.push_back(make_pair(3,1));
	v.push_back(make_pair(3,2));
	v.push_back(make_pair(4,1));
	v.push_back(make_pair(5,3));
	v.push_back(make_pair(5,4));
	v.push_back(make_pair(6,2));
	v.push_back(make_pair(6,5));
	v.push_back(make_pair(7,2));
	*/
	v.push_back(make_pair(5,8));
	v.push_back(make_pair(3,5));
	v.push_back(make_pair(1,9));
	v.push_back(make_pair(4,5));
	v.push_back(make_pair(0,2));
	v.push_back(make_pair(1,9));
	v.push_back(make_pair(7,8));
	v.push_back(make_pair(4,9));
	Solution s;
	cout << s.canFinish(10, v) << endl;

	return 0;
}