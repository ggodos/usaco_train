/*
ID: deadly51
TASK: castle
LANG: C++
*/
// sagosag51 collab
#include <bits/stdc++.h>


//   0    1    2   3    4    5     6
// ####|####|####|####|####|####|#####
// #   |   #|#   |   #|#   |    |    # 1
// ####|   #|####|   #|#   |####|    #
// ----|----|----|----|----|----|-----
// ####|#   |####|#  #|#  #|####|#   #
// #  #|#   |   #|#  #|#  #|#  #|#   # 2
// #  #|####|   #|####|#  #|####|#   #
// ----|----|----|----|----|----|-----
// #   |####|   #|####|#  #|####|#   #
// #   |    |   #|#  #|#  #|#  #|#   # 3
// #   |####|####|#  #|####|#  #|#   #
// ----|----|----|----|----|----|-----
// #  #|####|####|    |####|   #|#   # 4
// #  #|#   |    |    |    |   #|#   #
// ####|####|####|####|####|####|#####


// #############################
// #      ##      ##           # 
// ####   #####   ##   ####    #
// #####   #####  ##  ######   #
// #  ##      ##  ##  ##  ##   # 
// #  #####   ######  ######   #
// #   ####   ######  ######   #
// #          ##  ##  ##  ##   # 
// #   #########  ######  ##   #
// #  #########    ####   ##   # 
// #  ##                  ##   #
// #############################

using namespace std;

const char walls[] {'D', 'R', 'U', 'L'};
vector<bool> visited;
vector<vector<int>> g;
vector<int> comp;
vector<vector<int>> components;


void dfs (int v) {
    visited[v] = true;
    comp.push_back(v);
    for (size_t i=0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!visited[to])
            dfs(to);
    }
}

void find_comps() {
    for (int i = 0; i < g.size(); i++)
        visited[i] = false;
    for (int i = 0; i < g.size(); i++)
        if (!visited[i]) {
            comp.clear();
            dfs (i);
            components.push_back(comp);
        }
}


vector<char> getWalls(int number) {
    vector<char> temp;
    bool w[4] = { false };
    if (number == 0) {
        for (auto& i : walls)
            temp.push_back(i);
        return temp;
    }
    while (number != 0) {
        if (number >= 8) {
            w[0] = true;
            number -= 8;
        }
        if (number >= 4) {
            w[1] = true;
            number -= 4;
        }
        if (number >= 2) {
            w[2] = true; 
            number -= 2;
        }
        if (number == 1) {
            w[3] = true;
            number--;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!w[i])
            temp.push_back(walls[i]);
    }
    return temp;
}

inline void printGraph(vector<vector<int>>& g) {
    for (int i = 0; i < (int)g.size(); ++i) {
        cout << '[' << i + 1 << "] => {";
        for (int& j : g[i]) {
            cout << ' ' << j + 1;
        }
        cout << " }\n";
    }
}

int main() {
    //auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0);
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    int M, N;
    fin >> M >> N;
    g = vector<vector<int>>(N*M);
    visited = vector<bool>(N*M, false);
    for (int i = 0; i < N*M; i++) {
        int t;
        fin >> t;
        vector<char> invec = getWalls(t);
        
        for (auto& it : invec) {
            switch (it) {
                case 'L':
                    g[i].push_back(i-1);
                    break;
                case 'R':
                    g[i].push_back(i+1);
                    break;
                case 'U':
                    g[i].push_back(i-M);
                    break;
                case 'D':
                    g[i].push_back(i+M);
                    break;
            }
        }
    }

    find_comps();
    sort(components.begin(), components.end(),
        [](const vector<int>& x, const vector<int>& y) {
            return x.size() > y.size();
        }
    );

    unsigned int res = 0;
    pair<unsigned int, unsigned int> stena;
    for (int i = 0; i < components.size(); i++) {
        for (auto j : components[i]) {
            int ver[] = { 
            ((j-1) % M == M - 1) ? -1 : j-1, 
            (j+1) % M == 0 ? -1 : j+1, 
            (j-M) < 0 ? -1 : j-M, 
            (j+M) > N-1 ? -1 : j+M
            };
            for (auto k = components.begin() + i + 1; k != components.end(); k++) {
                for (auto z : ver) {
                    if (z != -1 && (find((*k).begin(), (*k).end(), z) != (*k).end())) {
                        int t = components[i].size() + (*k).size();
                        if (res <= t) {
                            res = t;
                            stena = make_pair(j, z);
                        }
                    }
                }
            }
        }
    }
    int out1 = 0, out2 = 0;
    out1 = (stena.first / M) + 1;
    out2 = (stena.first % M) + 1;
    char dir = 'N';
    int tmp = stena.first - stena.second;
    if (tmp == 1) dir = 'W';
    else if (tmp == -1) dir = 'E';
    else if (tmp == M - 1) dir = 'N';
    else if (tmp == -M + 1) dir = 'S';


    fout << 
    components.size() << "\n" << 
    components[0].size() << "\n" << 
    res << "\n" << 
    out1 << " " << out2 << " " << dir << "\n";
    
    // auto stop = chrono::high_resolution_clock::now();
    // cout << (stop - start).count() * 1e-9 << "\n";

    // for (auto& i : components) {
    //     for (auto& j : i)
    //         cout << j << " ";
    //     cout << "\n";
    // }
    // printGraph(g);
    return 0;
}








// 27
// 55
// 85
// 11_11_E
// ---- your output ---------
// 27
// 55
// 85
// 8_11_E