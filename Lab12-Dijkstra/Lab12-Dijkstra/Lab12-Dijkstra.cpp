#include <iostream>
#include <climits>
using namespace std;

int minDistance(int dis[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dis[v] <= min) {
            min = dis[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int V, int S, int G[50][50]) {
    int dis[V]; // The output array. dis[i] will hold the shortest distance from source to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dis[i] = INT_MAX, sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dis[S] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dis, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dis value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && G[u][v] && dis[u] != INT_MAX && dis[u] + G[u][v] < dis[v]) {
                dis[v] = dis[u] + G[u][v];
            }
        }
    }

    // Print the constructed distance array
    cout << "Vertex\t\tDistance from Source Vertex\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dis[i] << endl;
    }
}

// Main function
int main() {
    int V, S, G[50][50];
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the source vertex: ";
    cin >> S;
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> G[i][j];
        }
    }
    dijkstra(V, S, G);
    return 0;
}
