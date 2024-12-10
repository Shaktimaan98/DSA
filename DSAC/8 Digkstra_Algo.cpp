#include<iostream>
#include<string.h>

using namespace std;

class Graph {
    char Vnames[10][10];
    int n, cost[10][10];
public:
    Graph();
    int Position(char key[10]);
    void create_graph();
    void display();
    void Dijkstra();
};

Graph::Graph() {
    n = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = 999;  // Default value for unreachable nodes
        }
    }
}

void Graph::create_graph() {
    char ans, Start[10], End[10];
    int wt, i, j;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "\nEnter vertex names: ";
    for (i = 0; i < n; i++) {
        cin >> Vnames[i];
    }

    do {
        cout << "\nEnter Start and End point of edge: ";
        cin >> Start >> End;
        cout << "Enter weight: ";
        cin >> wt;
        i = Position(Start);
        j = Position(End);
        cost[i][j] = cost[j][i] = wt;
        cout << "\nMore Edges (y/n)? ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

void Graph::display() {
    cout << "\nAdjacency Matrix (Cost of edges between vertices):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "\t" << cost[i][j];
        }
        cout << endl;
    }
}

int Graph::Position(char key[10]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(Vnames[i], key) == 0)
            return i;
    }
    return -1; // Vertex not found
}

void Graph::Dijkstra() {
    int dis[10], flag[10], min, mnode, u, v;
    char Start[10];
    cout << "\nEnter Source vertex: ";
    cin >> Start;
    
    u = Position(Start);
    if (u == -1) {
        cout << "\nInvalid source vertex!" << endl;
        return;
    }

    // Initialize the distance array
    for (int i = 0; i < n; i++) {
        dis[i] = cost[u][i];
        flag[i] = 0;
    }
    dis[u] = 0;
    flag[u] = 1;

    cout << "\nVertex\tDistance from Source" << endl;
    cout << Vnames[u] << "\t" << dis[u] << endl;

    // Main loop of Dijkstra's Algorithm
    for (int i = 1; i < n; i++) {
        min = 999;
        // Find the vertex with the smallest distance
        for (v = 0; v < n; v++) {
            if (flag[v] == 0 && dis[v] < min) {
                min = dis[v];
                mnode = v;
            }
        }

        flag[mnode] = 1; // Mark this vertex as visited

        // Update the distances for the neighbors of the selected vertex
        for (v = 0; v < n; v++) {
            if (flag[v] == 0 && cost[mnode][v] != 999) { // If there is an edge
                if (dis[v] > dis[mnode] + cost[mnode][v]) {
                    dis[v] = dis[mnode] + cost[mnode][v];
                }
            }
        }

        // Display the updated distances after visiting this vertex
        cout << Vnames[mnode] << "\t" << dis[mnode] << endl;
    }

    cout << "\nFinal Shortest Distances from Source " << Start << ":\n";
    for (int i = 0; i < n; i++) {
        if (dis[i] == 999)
            cout << Vnames[i] << ": INF\n";  // If the vertex is unreachable
        else
            cout << Vnames[i] << ": " << dis[i] << endl;
    }
}

int main() {
    Graph obj;

    obj.create_graph();
    obj.display();
    obj.Dijkstra();

    return 0;
}

