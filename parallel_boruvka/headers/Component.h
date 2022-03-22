#pragma once

#include <vector>
#include <tuple>
#include "Vertex.h"
#include "Relation.h"
#include "Edge.h"

class Component {
public:
	std::vector<Vertex*> vertices;
	std::vector<Relation> relations;

	Component(Vertex* vertex);

	Component(std::vector<Vertex*> vertices);

	void add(Vertex* vertex);

	void add(std::vector<Vertex*> vertices);

	Edge findMinimumWeightEdge();

	bool contains(Component component);

	bool contains(Vertex* vertex);
};