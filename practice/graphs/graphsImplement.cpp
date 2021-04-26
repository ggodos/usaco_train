#include <istream>
#include <fstream>
#include <vector>
#include <limits>
#include "graphs.h"
using namespace std;

Graph::Graph(int N = 0, bool d = false) {
    adj = vector<vector<pair<int, int>>>(++N);
    visited.assign(adj.size(), false);
    colors.assign(adj.size(), 'w');
    directed = d;
    dist = vector<int>(N, INT_MAX);
}

void Graph::read() {
    int v = 1, e = 0, w = 0;
    if (directed) {
        for (;;) {
            v = e = w = 0;
            cin >> v;
            if (v == 0) break;
            cin >> e; cin >> w;
            adj[v].push_back(make_pair(e, w));
        }
    } else {
        for (;;) {
            v = e = 0;
            cin >> v;
            if (v == 0) break;
            cin >> e;
            adj[v].push_back(make_pair(e, 1));
        }
    }
}


void Graph::read(ifstream& in) {
    int v = 1, e = 0, w = 0;
    if (directed) {
        for (;;) {
            v = e = w = 0;
            in >> v;
            if (v == 0) break;
            in >> e; in >> w;
            adj[v].push_back(make_pair(e, w));
        }
    } else {
        for (;;) {
            v = e = 0;
            in >> v;
            if (v == 0) break;
            in >> e;
            adj[v].push_back(make_pair(e, 1));
        }
    }
}

void Graph::print(void) {
    for (int v = 1; v < adj.size(); v++) {
        cout << v << " -> ";
        for (auto& e : adj[v]) {
            cout << e.first << " " << e.second << " | ";
        }
        cout << "\n";
    }
}
bool Graph::cycleNoDir(int vertex, int prev) {
    bool res = false;
    if (visited[vertex]) return true;
    visited[vertex] = true;
    for (auto& u : adj[vertex]) {
        if (u.first == prev) continue;
        res = cycleNoDir(u.first, vertex);
    }
    return res;
}
bool Graph::cycleDir(int vertex) {
    colors[vertex] = 'g';
    for (auto& u : adj[vertex]) {
        if (colors[u.first] == 'w') if (cycleDir(u.first)) return true;
        else if (colors[u.first] == 'g') return true;
    }
    colors[vertex] = 'b';
    return false;
}
bool Graph::cycleExist() {
    if (directed) {
        fill(colors.begin(), colors.end(), 'w');
        for (int i = 1; i < adj.size(); i++) {
            if (colors[i] == 'w') if (cycleDir(1)) return true;
            }
    } else {
        fill(visited.begin(), visited.end(), 0);
        for (int i = 1; i < adj.size(); i++) {
            if (visited[i] == false) if (cycleNoDir(1, 0)) return true;
        }
    }
    return false;
}
void Graph::dfs(int vertex, int prev) {
    if (visited[vertex]) return;
    visited[vertex] = true;
    for (auto& u : adj[vertex]) {
        if (u.first == prev) continue;
        dfs(u.first, vertex);
    }
}
int Graph::connectComponent() {
    fill(visited.begin(), visited.end(), 0);
    int res = 0;
    for (int i = 1; i < visited.size(); i++) 
        if (visited[i] == false) {
            res++;
            dfs(i, i);
        }
    return res;
}

int Graph::minPathFind(int from, int to) {
    fill(dist.begin(), dist.end(), INT_MAX);
    return 1;
}