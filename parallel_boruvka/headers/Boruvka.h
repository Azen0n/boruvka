#include <vector>
#include "Component.h"
#include "Edge.h"
#include "Graph.h"

class Boruvka {
public:
	std::vector<Edge> minimumSpanningTree;
	Graph graph;
	RelationMatrix relationMatrix;

	Boruvka(Graph graph);

	void run();

	void printMST();

private:
	std::vector<Component> components;

	void addEdge(Edge edge);

	bool isEdgeExist(Edge edge);
};