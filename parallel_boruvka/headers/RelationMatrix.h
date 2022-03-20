#pragma once

#include <vector>

class RelationMatrix {
public:
	int width;

	RelationMatrix(int width);

	RelationMatrix();

	int get(int x, int y);

	void set(int x, int y, int value);

private:
	std::vector<int> matrix;
};