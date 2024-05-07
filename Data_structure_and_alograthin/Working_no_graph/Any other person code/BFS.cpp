#include <iostream>
/*
In this code, the tree is represented using an adjacency matrix, where tree[i][j] is 1 if there is an edge from node i to node j, 
and 0 otherwise. The bfs function takes the starting node as an argument and returns the level of each node in the tree. 
The main function reads the input and performs the BFS, printing the results.
*/

using namespace std;

const int MAX_NODES = 100;  // Maximum number of nodes in the tree

int tree[MAX_NODES][MAX_NODES];  // Representation of the tree
int level[MAX_NODES];  // Level of each node in the tree
bool visited[MAX_NODES];  // To keep track of visited nodes
int numNodes;  // Total number of nodes in the tree

void bfs(int startNode) {
    // Mark the starting node as visited and set its level to 0
    visited[startNode] = true;
    level[startNode] = 0;

    // Use two arrays, 'currLevel' and 'nextLevel', to keep track of nodes at the current and next levels
    int currLevel[MAX_NODES], nextLevel[MAX_NODES];
    int currLevelSize = 1, nextLevelSize = 0;
    currLevel[0] = startNode;

    // Repeat the following steps until all nodes have been visited
    while (currLevelSize > 0) {
        for (int i = 0; i < currLevelSize; i++) {
            int currNode = currLevel[i];

            // Visit all unvisited neighbors of the current node
            for (int j = 0; j < numNodes; j++) {
                if (tree[currNode][j] && !visited[j]) {
                    visited[j] = true;
                    level[j] = level[currNode] + 1;
                    nextLevel[nextLevelSize++] = j;
                }
            }
        }

        // Move on to the next level
        currLevelSize = nextLevelSize;
        nextLevelSize = 0;
        for (int i = 0; i < currLevelSize; i++) {
            currLevel[i] = nextLevel[i];
        }
    }
}

int main() {
    // Read the input and initialize the tree representation
    cin >> numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            cin >> tree[i][j];
        }
    }

    // Perform BFS starting from node 0
    bfs(0);

    // Print the level of each node
    for (int i = 0; i < numNodes; i++) {
        cout << "Node " << i << " is at level " << level[i] << endl;
    }

    return 0;
}

