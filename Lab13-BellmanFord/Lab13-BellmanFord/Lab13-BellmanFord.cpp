#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bellmanFord(int V, int E, int S, vector<vector<int>>& edges) {
    vector<int> dis(V, INT_MAX);
    dis[S] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
                dis[v] = dis[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if (dis[u] != INT_MAX && dis[u] + weight < dis[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex\t\tDistance from Source Vertex\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dis[i] << endl;
    }
}

int main() {
    int V, E, S;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the source vertex: ";
    cin >> S;

    vector<vector<int>> edges(E);
    int u, v, w;

    cout << "Enter the edges in the format [u, v, w]:\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    bellmanFord(V, E, S, edges);
    return 0;
}
