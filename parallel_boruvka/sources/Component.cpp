#include <vector>
#include <tuple>
#include "Component.h"
#include "Relation.h"
#include "Edge.h"

Component::Component(Vertex* vertex) {
	add(vertex);
}

Component::Component(std::vector<Vertex*> vertices) {
	add(vertices);
}

void Component::add(Vertex* vertex) {
	if (std::find(this->vertices.begin(), this->vertices.end(), vertex) == this->vertices.end()) {
		this->vertices.push_back(vertex);
		for (Relation relation : vertex->relations) {
			this->relations.push_back(relation);
		}

		// Erasing self (within component) relations
		auto it = std::remove_if(this->relations.begin(), this->relations.end(), [this](auto const& relation) {
			for (Vertex* vertex : this->vertices) {
				if (relation.vertex->id == vertex->id) {
					return true;
				}
			}
			return false;
			});
		this->relations.erase(it, this->relations.end());
	}
}

void Component::add(std::vector<Vertex*> vertices) {
	for (Vertex* vertex : vertices) {
		add(vertex);
	}
}

Edge Component::findMinimumWeightEdge() {
	Relation minimumWeightRelation = this->relations[0];
	for (Relation relation : this->relations) {
		if (relation.weight < minimumWeightRelation.weight) {
			minimumWeightRelation = relation;
		}
	}
	Vertex* firstVertex;
	for (Vertex* vertex : this->vertices) {
		if (std::find(vertex->relations.begin(), vertex->relations.end(), minimumWeightRelation) != vertex->relations.end()) {
			firstVertex = vertex;
			break;
		}
	}
	return Edge(firstVertex, minimumWeightRelation.vertex, minimumWeightRelation.weight);
}

bool Component::contains(Component component) {
	for (Vertex* vertex : component.vertices) {
		if (std::find(this->vertices.begin(), this->vertices.end(), vertex) != this->vertices.end()) {
			return true;
		}
	}
	return false;
}

bool Component::contains(Vertex* vertex) {
	if (std::find(this->vertices.begin(), this->vertices.end(), vertex) != this->vertices.end()) {
		return true;
	}
	return false;
}