#pragma once

#include "Vertex.h"

class Vertex;

class Relation {
public:
	Vertex* vertex;
	int weight;

	Relation(Vertex* vertex, int weight);

	bool operator==(const Relation& relation);
};