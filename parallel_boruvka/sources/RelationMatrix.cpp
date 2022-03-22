#include <vector>
#include "RelationMatrix.h"

RelationMatrix::RelationMatrix(int width) {
	this->width = width;
	std::vector<int> temp(width * width);
	this->matrix = temp;
}

RelationMatrix::RelationMatrix() {
	this->width = 0;
}

int RelationMatrix::get(int x, int y) {
	if (x >= width || y >= width)
		throw std::exception("Vector index out of range.");
	return this->matrix[x * this->width + y];
}

void RelationMatrix::set(int x, int y, int value) {
	if (x >= width || y >= width)
		throw std::exception("Vector index out of range.");
	this->matrix[x * this->width + y] = value;
	this->matrix[y * this->width + x] = value;
}

void RelationMatrix::print() {
	for (int i = 0; i < this->width; ++i) {
		for (int j = 0; j < this->width; ++j) {
			printf("%-2i ", get(i, j));
		}
		printf("\n");
	}
	printf("\n");
}

void RelationMatrix::traverse(int vertexId, std::vector<bool>& visitedVertices, Direction direction) {
	if (direction == Direction::HORIZONTAL) {
		for (int i = 0; i < this->width; ++i) {
			if (get(vertexId, i) != 0 && visitedVertices[i] == false) {
				visitedVertices[i] = true;
				traverse(i, visitedVertices, Direction::VERTICAL);
			}
		}
	}
	else {
		for (int i = 0; i < this->width; ++i) {
			if (get(i, vertexId) != 0 && visitedVertices[i] == false) {
				visitedVertices[i] = true;
				traverse(i, visitedVertices, Direction::HORIZONTAL);
			}
		}
	}
}

bool RelationMatrix::isConnected() {
	std::vector<bool> visitedVertices(this->width, false);
	visitedVertices[0] = true;
	traverse(0, visitedVertices, Direction::HORIZONTAL);

	if (std::find(visitedVertices.begin(), visitedVertices.end(), false) == visitedVertices.end()) {
		return true;
	}
	return false;
}