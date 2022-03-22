#include <iostream>
#include <vector>
#include <algorithm>

#include "headers/Graph.h"
#include "headers/Boruvka.h"

int main()
{
	srand((unsigned int)time(0));

	int numberOfVertices = 5;
	int numberOfEdges = 7;
	int minWeight = 10;
	int maxWeight = 50;

	try {
		Graph graph(numberOfVertices, numberOfEdges, minWeight, maxWeight);
		Boruvka boruvka(graph);
		boruvka.run();

		printf("Number of vertices: %i, number of edges: %i\n", numberOfVertices, numberOfEdges);
		graph.relationMatrix.print();
		boruvka.printMST();
	}
	catch (std::exception& e) {
		printf("%s\n", e.what());
	}
	return 0;
}