#Biconnectivity in Undirected graphs

Supose that the graph represents a communicationnetwork, we can ask ourselves if removing an edge or vertex leaves a part of the network unreachable. We are interested in staying connected if an edge or vertex is removed.

There are two related definitions of biconnectivity:

##Edge-connectivity

A bridge in a graph is an edge that, if removed, would seperate a connected graph into two disjoint subgraphs. A graph that has no bridges is said to be edge-connected

##Biconnectivity

An articulation point in a graph is a vertex that, if removed, would seperate a connected graph into at least two disjoint subgraphs. A graph is said to be biconnected if every pair of vertices is connected by two disjoint paths.
