#include <vector>
#include <algorithm>
#include "Graph.h"
#include "RelationMatrix.h"
#include "Vertex.h"
#include "Edge.h"

Graph::Graph(int numberOfVertices, int numberOfEdges, int minWeight, int maxWeight) {
	validateParameters(numberOfVertices, numberOfEdges);
	this->numberOfVertices = numberOfVertices;
	this->numberOfEdges = numberOfEdges;
	this->minWeight = minWeight;
	this->maxWeight = maxWeight;

	RelationMatrix temp(numberOfVertices);
	this->relationMatrix = temp;

	for (int i = 0; i < this->numberOfVertices; ++i) {
		this->vertices.push_back(Vertex(i));
	}

	buildMinNumberOfEdges();
}

void Graph::printRelations() {
	for (int i = 0; i < this->numberOfVertices; ++i) {
		for (int j = 0; j < this->numberOfVertices; ++j) {
			printf("%-2i ", this->relationMatrix.get(i, j));
		}
		printf("\n");
	}
}
void Graph::validateParameters(int numberOfVertices, int numberOfEdges) {
	if (numberOfVertices < 1)
		throw std::exception("Number of vertices must be greater than 1.");
	if (numberOfEdges < numberOfVertices - 1)
		throw std::exception("Number of edges must be greater.");
	if (numberOfEdges > numberOfVertices * (numberOfVertices - 1) / 2)
		throw std::exception("Number of edges must be less.");
}

void Graph::buildMinNumberOfEdges() {
	Vertex initialVertex = this->vertices[rand() % this->numberOfVertices];
	std::vector<Vertex> connectedVertices = { initialVertex };
	std::vector<Vertex> unconnectedVertices(this->vertices);
	unconnectedVertices.erase(std::remove(unconnectedVertices.begin(), unconnectedVertices.end(), initialVertex), unconnectedVertices.end());
	std::random_shuffle(unconnectedVertices.begin(), unconnectedVertices.end());

	for (int i = 0; i < this->numberOfVertices - 1; ++i) {
		Vertex connectedVertex = connectedVertices[rand() % connectedVertices.size()];
		Vertex unconnectedVertex = unconnectedVertices[unconnectedVertices.size() - 1];
		unconnectedVertices.pop_back();
		connectedVertices.push_back(unconnectedVertex);

		int weight = this->minWeight + rand() % this->maxWeight;
		this->relationMatrix.set(connectedVertex.id, unconnectedVertex.id, weight);
		this->edges.push_back(Edge(&connectedVertex, &unconnectedVertex, weight));
	}
}