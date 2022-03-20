#include <iostream>
#include <vector>
#include <algorithm>

#include "headers/Graph.h"

int main()
{
	srand(time(0));

	int numberOfVertices = 10;
	int numberOfEdges = 9;
	int minWeight = 1;
	int maxWeight = 20;

	try {
		Graph graph(numberOfVertices, numberOfEdges, minWeight, maxWeight);
		graph.printRelations();
	}
	catch (std::exception& e) {
		printf("%s\n", e.what());
	}
	return 0;
}