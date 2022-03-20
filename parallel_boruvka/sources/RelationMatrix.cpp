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