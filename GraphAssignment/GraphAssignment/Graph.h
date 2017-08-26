#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <string>
#include <sstream>
class Graph
{
public:	
	vector<GraphNode> nodes;  // Array of nodes of graph – will be given space once the size is known
	vector<GraphNode> topoNodes;
	int nodeCt;    // Size of G
	Graph(int size)  { 
		nodeCt = size;
		initializeGraph();
	};  // create node array
	void initializeGraph(){
		for (int i = 0; i < nodeCt; i++){
			GraphNode node;
			node.name = "node";
			node.nodeID = i;
			nodes.push_back(node);
		}
	}
	string toString(){
		stringstream ss;
		for (int i = 0; i < nodeCt; i++){
			ss << nodes[i].name << endl;	
		}
		return ss.str();
	}
	int shortestPathLength(int first, int second){

	}
	int shortestCommonAncestor(int first, int second){
		return 0;
	}
	int shortestAncestralPath(int first, int second){
		return 0;
	}
	void topofy(){
		for (int i = 0; i < nodeCt; i++){
			if (nodes[i].visited) continue;
			else topofy(i);
		}
	}
	void topofy(int id){
		if ()
	}
	void addEdge(int node, int edge){
		if (node >= nodeCt || node < 0) return;
		nodes[node].parentIds.push_back(edge);
	}
}; 

#endif
