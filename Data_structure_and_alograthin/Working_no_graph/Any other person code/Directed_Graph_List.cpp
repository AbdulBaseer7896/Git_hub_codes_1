#include <iostream>
/*

Pai tayan nal Endddd ta Outputs v aa na, mera Veer oo Taa leen

*/

/*

Note that this code assumes an undirected tree and uses an adjacency matrix to represent the edges between nodes. 
The value of n is the number of nodes in the tree, and the input format is the edge list representation of the tree 
(i.e., a sequence of pairs u and v representing an edge from node u to node v). 
The dfs function takes an integer u as input, which represents the current node being visited, and prints out the node value as it visits it.

*/
class Edge {
public:
  int destination;
  int weight;
  Edge* next;

  Edge(int destination, int weight) {
    this->destination = destination;
    this->weight = weight;
    next = nullptr;
  }
};

class Graph {
public:
  int vertex_count;
  Edge** adjacency_list;

  Graph(int vertex_count) {
    this->vertex_count = vertex_count;
    adjacency_list = new Edge*[vertex_count];
    for (int i = 0; i < vertex_count; i++) {
      adjacency_list[i] = nullptr;
    }
  }

  void add_edge(int source, int destination, int weight) {
    Edge* new_edge = new Edge(destination, weight);
    new_edge->next = adjacency_list[source];
    adjacency_list[source] = new_edge;
  }
};

int main() {
  Graph graph(4);
  graph.add_edge(0, 1, 1);
  graph.add_edge(0, 2, 2);
  graph.add_edge(1, 2, 3);
  graph.add_edge(2, 3, 4);

  for (int i = 0; i < graph.vertex_count; i++) {
    Edge* edge = graph.adjacency_list[i];
    while (edge != nullptr) {
      std::cout << "Source: " << i << ", Destination: " << edge->destination
                << ", Weight: " << edge->weight << std::endl;
      edge = edge->next;
    }
  }

  return 0;
}


/*
Source: 2, Destination: 3, Weight: 4
Source: 2, Destination: 1, Weight: 3
Source: 2, Destination: 2, Weight: 2
Source: 0, Destination: 2, Weight: 2
Source: 0, Destination: 1, Weight: 1
*/






