#include <iostream>
#include <limits>
using namespace std;

class WeightedGraph {
private:
    int n;
    int **adj;

public:
    WeightedGraph(int n) {
        this->n = n;
        adj = new int *[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++) {
                adj[i][j] = (i == j) ? 0 : numeric_limits<int>::max();
            }
        }
    }

    ~WeightedGraph() {
        for (int i = 0; i < n; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }

    void add_edge(int origin, int destin, int weight) {
        if (origin > n || destin > n || origin <= 0 || destin <= 0 || weight < 0) {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = weight;
    }

    void delete_edge(int origin, int destin) {
        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            cout << "Invalid edge!\n";
            return;
        }
        adj[origin - 1][destin - 1] = numeric_limits<int>::max();
    }

    void display() {
        cout << "Weighted Adjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == numeric_limits<int>::max())
                    cout << "8  ";
                else
                    cout << adj[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

int main() {
    int nodes, edges, origin, destin, weight;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    if (edges > (nodes * nodes)) {
        cout << "Invalid number of edges!" << endl;
        return 0;
    }

    WeightedGraph wg(nodes);

    for (int i = 0; i < edges; i++) {
        cout << "Edge " << i + 1 << ":\n";
        cout << "Enter origin, destination, and weight: ";
        cin >> origin >> destin >> weight;

        if (origin == -1 || destin == -1)
            break;

        wg.add_edge(origin, destin, weight);
    }

    cout << "\nInitial weighted adjacency matrix:\n";
    wg.display();

    wg.delete_edge(1, 2);
    wg.delete_edge(2, 3);

    cout << "\nWeighted adjacency matrix after deleting edges:\n";
    wg.display();

    return 0;
}

