#include <vector>
#include "Boruvka.h"
#include "Component.h"
#include "Edge.h"
#include "Graph.h"


Boruvka::Boruvka(Graph graph) {
	this->graph = graph;

	RelationMatrix temp(graph.numberOfVertices);
	this->relationMatrix = temp;

	for (Vertex* vertex : graph.vertices) {
		this->components.push_back(Component(vertex));
	}
}

void Boruvka::run() {
	while (this->components.size() != 1) {
		std::vector<Component> newComponents;
		for (Component component : this->components) {
			Edge edge = component.findMinimumWeightEdge();
			addEdge(edge);

			std::vector<Component>::iterator it = std::find_if(newComponents.begin(), newComponents.end(), [&edge](Component& comp) {
				return comp.contains(edge.secondVertex);
				});
			if (it == newComponents.end()) {
				it = std::find_if(this->components.begin(), this->components.end(), [&edge](Component& comp) {
					return comp.contains(edge.secondVertex);
					});
			}
			Component anotherComponent = *it;
			Component unitedComponent(component.vertices);
			unitedComponent.add(anotherComponent.vertices);

			auto it2 = std::find_if(newComponents.begin(), newComponents.end(), [this, &unitedComponent](Component& comp) {
				return comp.contains(unitedComponent);
				});
			if (it2 == newComponents.end()) {
				newComponents.push_back(unitedComponent);
				if (unitedComponent.vertices.size() == this->graph.numberOfVertices) {
					this->components = { unitedComponent };
					break;
				}
			}
			else {
				(*it2).add(unitedComponent.vertices);
				if ((*it2).vertices.size() == this->graph.numberOfVertices) {
					this->components = { *it2 };
					break;
				}
			}
		}
		auto it = std::find_if(newComponents.begin(), newComponents.end(), [this](Component& comp) {
			return comp.vertices.size() == this->graph.numberOfVertices;
			});
		if (it != newComponents.end()) {
			this->components = { *it };
		}
		else {
			this->components = newComponents;
		}
	}
}

void Boruvka::printMST() {
	int totalWeight = 0;
	for (Edge edge : this->minimumSpanningTree) {
		edge.print();
		totalWeight += edge.weight;
	}
	printf("Total weight: %i, Number of edges: %i\n", totalWeight, this->minimumSpanningTree.size());
}

void Boruvka::addEdge(Edge edge) {
	if (!isEdgeExist(edge) && this->minimumSpanningTree.size() < this->graph.numberOfVertices - 1) {
		this->minimumSpanningTree.push_back(edge);
		this->relationMatrix.set(edge.firstVertex->id, edge.secondVertex->id, edge.weight);
	}
}

bool Boruvka::isEdgeExist(Edge edge) {
	for (Edge minimumWeightEdge : this->minimumSpanningTree) {
		if (minimumWeightEdge == edge) {
			return true;
		}
	}
	return false;
}