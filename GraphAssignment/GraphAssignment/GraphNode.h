#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <string>
#include <vector>


using namespace std;
class GraphNode
{
public:
	int nodeID;
	vector<int> parentIds;
	vector<int> childIds;
	string name;  
	bool visited; 
	GraphNode(){};
	GraphNode(int id, string nameEle){
		nodeID = id;
		name = nameEle;
		visited = false;
	}
};

#endif
