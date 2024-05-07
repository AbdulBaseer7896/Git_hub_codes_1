#include <iostream>
using namespace std;

const int MAX = 100;
int n; // number of nodes in the tree
bool g[MAX][MAX]; // adjacency matrix representation of the tree
bool visited[MAX]; // to keep track of the visited nodes

void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v = 0; v < n; v++) {
        if (g[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n;
    int u, v;
    while (cin >> u >> v) {
        g[u][v] = g[v][u] = true;
    }
    dfs(0);
    return 0;
}

