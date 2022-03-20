#include <vector>
#include "Vertex.h"

Vertex::Vertex(int id) {
	this->id = id;
}

bool Vertex::operator==(const Vertex& vertex) {
	return this->id == vertex.id;
}