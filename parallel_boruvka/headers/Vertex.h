#pragma once

#include <vector>
#include "Relation.h"

class Relation;

class Vertex {
public:
	int id;
	std::vector<Relation> relations;

	Vertex(int id);

	bool operator==(const Vertex& vertex);
};