﻿cmake_minimum_required (VERSION 3.8)

include_directories("headers")
include_directories("sources")

add_executable(main
main.cpp
headers/Boruvka.h
headers/Component.h
headers/Edge.h
headers/Graph.h
headers/Relation.h
headers/RelationMatrix.h
headers/Vertex.h
sources/Boruvka.cpp
sources/Component.cpp
sources/Edge.cpp
sources/Graph.cpp
sources/Relation.cpp
sources/RelationMatrix.cpp
sources/Vertex.cpp)