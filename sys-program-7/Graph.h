#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

    void DFSutil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adjList[v]) {
            if (!visited[u]) {
                DFSutil(u, visited);
            }
        }
    }

public:
    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void removeEdge(int u, int v) {
        adjList[u].erase(remove(adjList[u].begin(), adjList[u].end(), v), adjList[u].end());
        adjList[v].erase(remove(adjList[v].begin(), adjList[v].end(), u), adjList[v].end());
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "BFS: ";
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adjList[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS: ";
        DFSutil(start, visited);
        cout << endl;
    }

    bool isConnected() {
        vector<bool> visited(vertices, false);
        DFSutil(0, visited);
        return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }

    void print() {
        cout << "Граф (список смежности):" << endl;
        for (int i = 0; i < vertices; ++i) {
            cout << i << ": ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};