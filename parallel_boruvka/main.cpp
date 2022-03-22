#include <iostream>
#include <vector>
#include <algorithm>

#include "headers/Graph.h"
#include "headers/Boruvka.h"
#include "headers/RelationMatrix.h"

void test() {
	int numberOfVertices = 10;
	int numberOfEdges = 9;
	int minWeight = 10;
	int maxWeight = 50;

	for (int i = 2; i < 60; i++) {
		for (int j = i - 1; j <= i * (i - 1) / 2; ++j) {
			Graph graph(i, j, minWeight, maxWeight);
			Boruvka boruvka(graph);
			boruvka.run();
			printf("N = %i\tM = %i\t", i, j);
			graph.relationMatrix.isConnected() == true ? printf("Connected\n") : printf("Not connected\n");
		}
	}
}

void testOnce() {
	int numberOfVertices = 10;
	int numberOfEdges = 9;
	int minWeight = 10;
	int maxWeight = 50;

	Graph graph(numberOfVertices, numberOfEdges, minWeight, maxWeight);
	Boruvka boruvka(graph);
	boruvka.run();
	printf("Number of vertices: %i, number of edges: %i\n", numberOfVertices, numberOfEdges);
	graph.relationMatrix.print();
	graph.relationMatrix.isConnected() == true ? printf("Connected\n") : printf("Not connected\n");
	boruvka.printMST();
}

void traversalTest() {
	RelationMatrix relationMatrix(5);
	relationMatrix.set(0, 4, 1);
	relationMatrix.set(0, 3, 1);
	relationMatrix.set(1, 2, 1);
	relationMatrix.set(3, 4, 1);

	relationMatrix.print();
	relationMatrix.isConnected() == true ? printf("Connected\n") : printf("Not connected\n");
}

int main()
{
	srand((unsigned int)time(0));

	try {
		test();
	}
	catch (std::exception& e) {
		printf("%s\n", e.what());
	}
	return 0;
}