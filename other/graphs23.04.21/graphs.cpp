#include <bits/stdc++.h>
using namespace std;


void graphRead(vector<vector<pair<int, int>>> &adj, ifstream &input, bool weights);
void graphRead(vector<vector<pair<int, int>>> &adj, bool weights);
void graphPrint(vector<vector<pair<int, int>>> adj);
bool cycleFind(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int s, int t);
bool cycleExist(vector<vector<pair<int, int>>> adj);
void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int s, int t);
int connectComponent(vector<vector<pair<int, int>>> adj);

int main() {
    ifstream fin ("input.txt");
    int N;
    fin >> N;
    vector<vector<pair<int, int>>> adj(++N);

    graphRead(adj, fin, false);
    cout << "For graph: ";
    graphPrint(adj);
    if (cycleExist(adj)) {
        cout << "Cycle is exist.\n";
    } else {
        cout << "Cycle doesn't not exist.\n";
    }
    int cont_comp = connectComponent(adj);
    cout << "Connective = " << cont_comp << "\n";
    return 0;
}


void graphRead(vector<vector<pair<int, int>>> &adj, ifstream &input, bool weights) {
    int vertex = 0, edge = 0, length = 0;
    if (weights) {
        for (;;) {
            vertex = 0;
            input >> vertex;
            if (vertex == 0)
                break;
            input >> edge; input >> length;
            adj[vertex].push_back(make_pair(edge, length));
        }
    } else {
        for (;;) {
            vertex = 0;
            input >> vertex;
            if (vertex == 0)
                break;
            input >> edge;
            adj[vertex].push_back(make_pair(edge, 1));
        }
    }
}

void graphRead(vector<vector<pair<int, int>>> &adj, bool weights) {
    int vertex = 0, edge = 0, length = 0;
    if (weights) {
        for (;;) {
            vertex = 0;
            cin >> vertex;
            if (vertex == 0)
                break;
            cin >> edge; cin >> length;
            adj[vertex].push_back(make_pair(edge, length));
        }
    } else {
        for (;;) {
        vertex = 0;
        cin >> vertex;
        if (vertex == 0)
            break;
        cin >> edge;
        adj[vertex].push_back(make_pair(edge, 1));
        }
    }
}

void graphPrint(vector<vector<pair<int, int>>> adj) {
    cout << "\n";
    for (int v = 1; v < adj.size(); v++) {
        cout << v << " -> ";
        for (auto e : adj[v]) {
            cout << "|" << e.first << " " << e.second << "| ";
        }
        cout << "\n";
    }
}

bool cycleFind(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int s = 1, int t = 1) {
    bool res = false;
    if (visited[s]) return true;
    visited[s] = true;
    for (auto u : adj[s]) {
        if (u.first == t) continue;
        res = cycleFind(adj, visited, u.first, s);
    }
    return res;
}

bool cycleExist(vector<vector<pair<int, int>>> adj) {
    vector<bool> visited(adj.size(), false);
    bool res = cycleFind(adj, visited);
    return res;
}

void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int s, int t) {
    if (visited[s] && s != t) return;
    visited[s] = true;
    for (auto i : adj) {
        for (auto j : i) {
            if (j.first == t) continue;
            dfs(adj, visited, j.first, s);
        }
    }
}

int connectComponent(vector<vector<pair<int, int>>> adj) {
    vector<bool> visited(adj.size());
    visited[0] = true;
    int res = 0;
    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == false) {
            res++;
            dfs(adj, visited, i, i);
        }
    }
    return res;
}










