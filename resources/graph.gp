# data format of a line: label_of_vertex [array_of_neighbor_distance pairs]
# Following graph is a directed graph with 3 vertices where every vertice is has an edge to other ones.
# 
# tokat's ID is zero since it is our first vertex
# it is connected to vertex ID 1 and this edge has a length of 120
# it is connected to vertex ID 2 and this edge has a length ıf 1000
v0 1 120 2 1000
v1 0 120 2 950
v2 0 1000 1 950
v3 1 200
v4 0 250
v5 3 100 4 100 0 250