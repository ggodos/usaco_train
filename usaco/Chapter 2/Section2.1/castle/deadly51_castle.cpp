/*
ID: deadly51
TASK: castle
LANG: C++
*/
// sagosag51 collab
#include <bits/stdc++.h>


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

void printGraph(vector<vector<int>>& g) {
    for (int i = 0; i < (int)g.size(); ++i) {
        cout << '[' << i << "] => {";
        for (int& j : g[i]) {
            cout << ' ' << j;
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

    int res = 0;
    pair<int, int> stena = make_pair(0, 0);
    bool flag = false;
    for (int i = 0; i < (int)components.size() - 1; ++i) {
        for (int j = i + 1; j < (int)components.size(); ++j) {
            for (int k : components[i]) {
                int v[] = {
                    (k - 1) % M == M - 1 ? -1 : k - 1, //L
                    (k + 1) % M == 0     ? -1 : k + 1, //R
                    k < M                ? -1 : k - M, //U
                    k >= M * (N - 1)     ? -1 : k + M  //D
                };
                for (int s : v) {
                    if (s != -1 && find(components[j].begin(), components[j].end(), s) != components[j].end()) {
                        int sz = (int)components[i].size() + (int)components[j].size();
                        
                        if (res < sz) {
                            res = sz;
                            stena = make_pair(k, s);
                        } else if (res == sz) {
                            if (k%M+1 < stena.first%M+1) {
                                stena = make_pair(k, s);
                            } else if (k%M+1 == stena.first%M+1) {
                                if (k/M > stena.first/M) {
                                    stena = make_pair(k, s);
                                }
                            }
                        }
                        if (stena.first - stena.second == -M) {
                            int temp;
                            stena.first = temp;
                            stena.first = stena.second;
                            stena.second = temp;
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
    else if (tmp == M) dir = 'N';
    else if (tmp == -M) dir = 'S';

    fout << components.size() << "\n" << 
    components[0].size() << "\n" << 
    res << "\n" << 
    out1 << " " << out2 << " " << dir << "\n";

    // auto stop = chrono::high_resolution_clock::now();
    // cout << (stop - start).count() * 1e-9 << "\n";
    return 0;
}
