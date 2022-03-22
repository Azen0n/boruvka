#include <vector>
#include <algorithm>
#include "Graph.h"
#include "RelationMatrix.h"
#include "Vertex.h"
#include "Edge.h"

Graph::Graph(int numberOfVertices, int numberOfEdges, int minWeight, int maxWeight) {
	validateParameters(numberOfVertices, numberOfEdges, minWeight, maxWeight);
	this->numberOfVertices = numberOfVertices;
	this->numberOfEdges = numberOfEdges;
	this->minWeight = minWeight;
	this->maxWeight = maxWeight;

	RelationMatrix temp(numberOfVertices);
	this->relationMatrix = temp;

	for (int i = 0; i < this->numberOfVertices; ++i) {
		Vertex* vertex = new Vertex(i);
		this->vertices.push_back(vertex);
	}

	buildMinNumberOfEdges();
	buildRemainingEdges();
}

Graph::Graph(int numberOfVertices, std::vector<Edge> edges) {
	this->numberOfVertices = numberOfVertices;
	this->numberOfEdges = (int)edges.size();

	RelationMatrix temp(numberOfVertices);
	this->relationMatrix = temp;

	for (Edge edge : edges) {
		addEdge(edge.firstVertex, edge.secondVertex, edge.weight);

		if (std::find_if(edge.firstVertex->relations.begin(), edge.firstVertex->relations.end(), [&edge](Relation const& relation) {
			return relation.vertex->id == edge.secondVertex->id;
			}) == edge.firstVertex->relations.end()) {
			edge.firstVertex->relations.push_back(Relation(edge.secondVertex, edge.weight));
		}

		if (std::find(this->vertices.begin(), this->vertices.end(), edge.firstVertex) == this->vertices.end()) {
			this->vertices.push_back(edge.firstVertex);
		}
		if (std::find(this->vertices.begin(), this->vertices.end(), edge.secondVertex) == this->vertices.end()) {
			this->vertices.push_back(edge.secondVertex);
		}
	}
}

Graph::Graph() { }

void Graph::validateParameters(int numberOfVertices, int numberOfEdges, int minWeight, int maxWeight) {
	if (numberOfVertices < 1)
		throw std::exception("Number of vertices must be greater than 1.");
	if (numberOfEdges < numberOfVertices - 1)
		throw std::exception("Number of edges must be greater.");
	if (numberOfEdges > numberOfVertices * (numberOfVertices - 1) / 2)
		throw std::exception("Number of edges must be less.");
	if (minWeight > maxWeight)
		throw std::exception("Min weight must be less than Max weight.");
}

void Graph::buildMinNumberOfEdges() {
	Vertex* initialVertex = this->vertices[rand() % this->numberOfVertices];
	std::vector<Vertex*> connectedVertices = { initialVertex };
	std::vector<Vertex*> unconnectedVertices(this->vertices);
	unconnectedVertices.erase(std::remove(unconnectedVertices.begin(), unconnectedVertices.end(), initialVertex), unconnectedVertices.end());
	std::random_shuffle(unconnectedVertices.begin(), unconnectedVertices.end());

	for (int i = 0; i < this->numberOfVertices - 1; ++i) {
		Vertex* connectedVertex = connectedVertices[rand() % connectedVertices.size()];
		Vertex* unconnectedVertex = unconnectedVertices[unconnectedVertices.size() - 1];
		unconnectedVertices.pop_back();
		connectedVertices.push_back(unconnectedVertex);

		int weight = this->minWeight + rand() % (this->maxWeight + 1 - this->minWeight);
		addEdge(connectedVertex, unconnectedVertex, weight);
	}
}

void Graph::addEdge(Vertex* firstVertex, Vertex* secondVertex, int weight) {
	this->relationMatrix.set(firstVertex->id, secondVertex->id, weight);
	this->edges.push_back(Edge(firstVertex, secondVertex, weight));
}

void Graph::buildRemainingEdges() {
	int numberOfRemainingEdges = this->numberOfEdges - (this->numberOfVertices - 1);

	if (numberOfRemainingEdges > 0) {
		std::vector<std::pair<int, int>> availableEdgeIndices;
		for (int i = 0; i < this->numberOfVertices - 1; ++i) {
			for (int j = i + 1; j < this->numberOfVertices; ++j) {
				if (this->relationMatrix.get(i, j) == 0) {
					availableEdgeIndices.push_back(std::pair<int, int>(i, j));
				}
			}
		}
		std::random_shuffle(availableEdgeIndices.begin(), availableEdgeIndices.end());

		for (int i = 0; i < numberOfRemainingEdges; ++i) {
			Vertex* firstVertex = this->vertices[availableEdgeIndices[i].first];
			Vertex* secondVertex = this->vertices[availableEdgeIndices[i].second];
			int weight = this->minWeight + rand() % (this->maxWeight + 1 - this->minWeight);
			addEdge(firstVertex, secondVertex, weight);
		}
	}
}