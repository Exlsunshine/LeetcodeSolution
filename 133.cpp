#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node == NULL)
            return NULL;
        
    	unordered_map<int, UndirectedGraphNode*> map;
    	return cloneGraphFromRoot(node, map);
    }

private:
	UndirectedGraphNode *cloneGraphFromRoot(UndirectedGraphNode *root, unordered_map<int, UndirectedGraphNode*> &map)
	{
		UndirectedGraphNode *newRoot = new UndirectedGraphNode(root->label);
		map.insert(pair<int, UndirectedGraphNode*>(newRoot->label, newRoot));

		for (int i = 0; i < root->neighbors.size(); ++i)
		{
			unordered_map<int, UndirectedGraphNode*>::iterator it = map.find(root->neighbors[i]->label);

			if (it == map.end())
				newRoot->neighbors.push_back(cloneGraphFromRoot(root->neighbors[i], map));
			else
				newRoot->neighbors.push_back(it->second);
		}

		return newRoot;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}