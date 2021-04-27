#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include "graphs.h"
using namespace std;


int main() {
    ifstream fin ("input.txt");
    int N;
    fin >> N;

    Graph g(N, true);

    g.read(fin);
    g.print();

    if (g.cycleExist()) {
        cout << "Cycle exist.\n";
    } else {
        cout << "Cycle doesn't exist.\n";
    }
    int g_conn = g.connectComponent();
    cout << "Graph conn comp = " << g_conn << "\n";
    
    // In developing
    int from = 1, to = 5;
    vector<int> path;
    int distance;
    tie(path, distance) = g.minPath(from, to);
    cout << "Distance from " << from << " vertex to " << to << " vertex is " << distance << "\n";
    cout << "Graph min path from " << from << " vertex to " << to << " vertex is:\n";
    for (auto& i : path) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}




