#include <istream>
#include <fstream>
#include <vector>
#include <limits>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>
#include "graphs.h"
using namespace std;

Graph::Graph(int N = 0, bool d = false) {
    size = ++N;
    adj = vector<vector<pair<int, int>>>(size);
    visited.assign(size, false);
    colors.assign(size, 'w');
    directed = d;
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
    int v = 0, e = 0, w = 0;
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
    for (int v = 1; v < size; v++) {
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
        for (int i = 1; i < size; i++) {
            if (colors[i] == 'w') if (cycleDir(1)) return true;
            }
    } else {
        fill(visited.begin(), visited.end(), 0);
        for (int i = 1; i < size; i++) {
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
    for (int i = 1; i < size; i++) 
        if (visited[i] == false) {
            res++;
            dfs(i, i);
        }
    return res;
}


int Graph::getDistanceFromPath(vector<int> path) {
    int res = 0;
    for (int i = 1; i < path.size(); i++) {
        int temp = 0;
        for (auto& j : adj[i]) {
            if (j.first == i+1) {
                temp = j.second;
                break;
            }
        }
        cout << i << " " << i + 1 << "\n";
        cout << temp << "\n";
        res += temp;
    }
    cout << "\n";
    return res;
}

// In developing
vector<vector<int>> Graph::dijkstra(int s) {
    vector<bool> vis(size, false);
    vector<int> dist(size, INT_MAX);
    vector<int> prev(size, 0);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(s, 0));
    while (pq.size() != 0) {
        int index, minValue;
        tie(index, minValue) = pq.top();
        pq.pop();
        vis[index] = true;
        if (dist[index] < minValue) continue;
        for (auto edge : adj[index]) {
            if (vis[edge.first]) continue;
            int newDist = dist[index] + edge.second;
            if (newDist < dist[edge.first]) {
                prev[edge.first] = index;
                dist[edge.first] = newDist;
                pq.push(edge);
            }
        }
    }
    vector<vector<int>> res(2);
    res[0] = dist;
    res[1] = prev;
    return res;
}

// In developing
tuple<vector<int>, int> Graph::minPath(int from, int to) {
    vector<vector<int>> res = dijkstra(from);
    vector<int> path;
    if (res[1][to] == INT_MAX) return make_tuple(path, Graph::getDistanceFromPath(path));
    for (int at = to; at != 0; at = res[1][at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return make_tuple(path, Graph::getDistanceFromPath(path));
}

