#include <iostream>

using namespace std;

#define MAX_NODES 7 // Maximum number of nodes

class Graph {
private:
    int adj[MAX_NODES][MAX_NODES]; // Adjacency matrix
    bool visited[MAX_NODES];       // Visited array

public:
    Graph() {
        // Initialize adjacency matrix with 0 (no edges)
        for (int i = 0; i < MAX_NODES; i++)
            for (int j = 0; j < MAX_NODES; j++)
                adj[i][j] = 0;
    }

    // Function to add an edge (undirected graph)
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; // Since it's an undirected graph
    }

    // BFS using an array-based queue
    void BFS(int start) {
        bool visited[MAX_NODES] = {false};
        int queue[MAX_NODES];
        int front = 0, rear = 0;

        // Start BFS
        visited[start] = true;
        queue[rear++] = start; // Enqueue start node

        cout << "BFS Traversal: ";
        while (front < rear) {
            int node = queue[front++]; // Dequeue
            cout << node << " ";

            // Visit all unvisited neighbors
            for (int i = 0; i < MAX_NODES; i++) {
                if (adj[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i; // Enqueue neighbor
                }
            }
        }
        cout << endl;
    }

    // DFS Recursive Helper
    void DFS_Recursive_Helper(int node) {
        visited[node] = true;
        cout << node << " ";

        // Visit all connected nodes
        for (int i = 0; i < MAX_NODES; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                DFS_Recursive_Helper(i);
            }
        }
    }

    // DFS Recursive Function
    void DFS_Recursive(int start) {
        for (int i = 0; i < MAX_NODES; i++)
            visited[i] = false; // Reset visited array

        cout << "DFS Recursive Traversal: ";
        DFS_Recursive_Helper(start);
        cout << endl;
    }

    // DFS Iterative using an array-based stack
    void DFS_Iterative(int start) {
        bool visited[MAX_NODES] = {false};
        int stack[MAX_NODES];
        int top = -1;

        stack[++top] = start; // Push start node
        visited[start] = true;

        cout << "DFS Iterative Traversal: ";
        while (top >= 0) {
            int node = stack[top--]; // Pop from stack
            cout << node << " ";

            // Visit all unvisited neighbors (reverse order for correct DFS order)
            for (int i = MAX_NODES - 1; i >= 0; i--) {
                if (adj[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    stack[++top] = i; // Push neighbor
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;

    // Adding edges to create a simple graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    // Running BFS and DFS
    g.BFS(0);          // Start BFS from node 0
    g.DFS_Recursive(0); // Start DFS (Recursive) from node 0
    g.DFS_Iterative(0); // Start DFS (Iterative) from node 0

    return 0;
}
