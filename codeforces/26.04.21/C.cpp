#include <bits/stdc++.h>

using namespace std;

#define ll long long
pair<int, int> moves[] = {make_pair(1, 0), make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0)};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<vector<char>> g(r);
    for (auto& i : g)
        i.resize(c);
    for (int i = 0; i < r; i++) {
        char t;
        for (int j = 0; j < c; j++) {
            cin >> t;
            if (t == '.')
                g[i][j] = 'D';
            else g[i][j] = t;
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (g[j][i] == 'S') {
                for (auto e : moves) {
                    int x = i + e.first;
                    int y = j + e.second;
                    if (x >= 0 && y >= 0 && x < c && y < r) {
                        if (g[y][x] == 'W') { 
                            cout << "No";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "Yes\n";
    for (auto i : g) {
        for (auto j : i)
            cout << j;
        cout << "\n";
    }
    return 0;
}