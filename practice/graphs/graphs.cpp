#include <iostream>
#include <fstream>
#include <vector>
#include "graphs.h"
using namespace std;


int main() {
    ifstream fin ("input.txt");
    int N;
    fin >> N;
    Graph g(N, false);
    g.read(fin);
    g.print();
    if (g.cycleExist()) {
        cout << "Cycle exist.\n";
    } else {
        cout << "Cycle doesn't exist.\n";
    }
    int g_conn = g.connectComponent();
    cout << "Graph conn comp = " << g_conn << "\n";

    return 0;
}




