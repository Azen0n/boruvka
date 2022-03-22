#include "Vertex.h"

Relation::Relation(Vertex* vertex, int weight) {
	this->vertex = vertex;
	this->weight = weight;
}

bool Relation::operator==(const Relation& relation) {
	return (this->vertex == relation.vertex && this->weight == relation.weight);
}