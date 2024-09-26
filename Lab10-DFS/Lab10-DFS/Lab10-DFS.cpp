#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int v);
    void addEdge(int source, int destination);
    void DFS(int vertex);
    void BFS(int startVertex);

};

void Graph::addEdge(int source, int destination){
    adjLists[source].push_front(destination);
}

Graph::Graph(int v) {
    numVertices = v;
    adjLists = new list<int>[v];
    visited = new bool[v];
    fill_n(visited, v, false);
}

void Graph::DFS(int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbour : adjLists[vertex]) {
        if (!visited[neighbour]) {
            DFS(neighbour);
        }
    }
    delete[] visited;
}

void Graph::BFS(int startVertex){
    queue<int> q;
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++){
        visited[i] = false;
    }

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()){
        int currentVertex = q.front();
        cout<<currentVertex<<" ";
        q.pop();

        for (int neighbour : adjLists[currentVertex]){
            if (!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    delete[] visited;
}


int main()
{
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 0); 

    
    

    cout<<"Depth First Traversal (starting from vertex 0)"<<endl;
    g.DFS(0);
    cout<<endl;

    cout<<"Breadth First Travercial (starting from vertex 0)"<<endl;
    g.BFS(0);
    cout<<endl;


    return 0;
}