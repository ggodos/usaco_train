#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using vb = vector<bool>;
using graph = vector<vector<pair<int, int>>>;

class Graph {
    private:
        graph adj;
        bool directed;
        vb visited;
        vector<char> colors;
        vector<int> dist;
        bool cycleNoDir(int vertex, int prev);
        bool cycleDir(int vertex);
        void dfs(int vertex, int prev);
    public:
        Graph(int N, bool d);
        void read();
        void read(ifstream& in);
        void print();
        bool cycleExist();
        int connectComponent();
        int minPathFind(int from, int to);
};