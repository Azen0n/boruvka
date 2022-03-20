#pragma once

#include <vector>
#include <algorithm>
#include "RelationMatrix.h"
#include "Vertex.h"
#include "Edge.h"

class Vertex;
class Edge;
class RelationMatrix;

class Graph {
public:
	int numberOfVertices;
	int numberOfEdges;
	std::vector<Vertex> vertices;
	std::vector<Edge> edges;

	int minWeight;
	int maxWeight;

	RelationMatrix relationMatrix;

	Graph(int numberOfVertices, int numberOfEdges, int minWeight, int maxWeight);

	void printRelations();

private:
	void validateParameters(int numberOfVertices, int numberOfEdges);

	void buildMinNumberOfEdges();
};