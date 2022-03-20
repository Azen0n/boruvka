#pragma once

class Vertex;

class Edge {
public:
	Vertex* firstVertex;
	Vertex* secondVertex;
	int weight;

	Edge(Vertex* firstVertex, Vertex* secondVertex, int weight);
};