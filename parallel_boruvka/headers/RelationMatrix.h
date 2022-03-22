#pragma once

#include <vector>

enum class Direction { HORIZONTAL, VERTICAL };

class RelationMatrix {
public:
	int width;

	RelationMatrix(int width);

	RelationMatrix();

	int get(int x, int y);

	void set(int x, int y, int value);

	void print();

	bool isConnected();

private:
	std::vector<int> matrix;

	void RelationMatrix::traverse(int vertexId, std::vector<bool>& visitedVertices, Direction direction);
};