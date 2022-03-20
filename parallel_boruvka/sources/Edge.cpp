#include "Edge.h"
#include "Vertex.h"
#include "Relation.h"

Edge::Edge(Vertex* firstVertex, Vertex* secondVertex, int weight) {
	this->firstVertex = firstVertex;
	this->secondVertex = secondVertex;
	this->weight = weight;

	this->firstVertex->relations.push_back(Relation(secondVertex, weight));
	this->secondVertex->relations.push_back(Relation(firstVertex, weight));
}