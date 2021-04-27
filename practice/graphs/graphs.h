#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
using graph = vector<vector<pair<int, int>>>;

class Graph {
    private:
        graph adj;
        vector<bool> visited;
        vector<char> colors;

        bool directed;
        int size;

        bool cycleNoDir(int vertex, int prev);
        bool cycleDir(int vertex);
        void dfs(int vertex, int prev);
        int getDistanceFromPath(vector<int> path);
    public:
        Graph(int N, bool d);
        void read();
        void read(ifstream& in);
        void print();
        bool cycleExist();
        int connectComponent();

        // In developing
        vector<vector<int>> dijkstra(int s);
        tuple<vector<int>, int> minPath(int from, int to);
};