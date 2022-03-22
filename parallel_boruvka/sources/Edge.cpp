#include "Edge.h"
#include "Vertex.h"
#include "Relation.h"

Edge::Edge(Vertex* firstVertex, Vertex* secondVertex, int weight) {
	this->firstVertex = firstVertex;
	this->secondVertex = secondVertex;
	this->weight = weight;

	if (std::find_if(this->firstVertex->relations.begin(), this->firstVertex->relations.end(), [&secondVertex](Relation const& relation) {
		return relation.vertex == secondVertex;
		}) == this->firstVertex->relations.end()) {
		this->firstVertex->relations.push_back(Relation(secondVertex, weight));
	}

	if (std::find_if(this->secondVertex->relations.begin(), this->secondVertex->relations.end(), [&firstVertex](Relation const& relation) {
		return relation.vertex == firstVertex;
		}) == this->secondVertex->relations.end()) {
		this->secondVertex->relations.push_back(Relation(firstVertex, weight));
	}
}

Edge::Edge() { }

bool Edge::operator==(const Edge& edge) {
	return (this->firstVertex == edge.firstVertex && this->secondVertex == edge.secondVertex) ||
		(this->secondVertex == edge.firstVertex && this->firstVertex == edge.secondVertex);
}

void Edge::print() {
	printf("%i --- %i (%i)\n", this->firstVertex->id, this->secondVertex->id, this->weight);
}