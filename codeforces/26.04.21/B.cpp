#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> g;

int dfs(int s) {
    int res = 1;
    if (g[s].size() == 0) return 1;
    for (auto u : g[s]) {
        res = max(res, dfs(u) + 1);
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    g.resize(++n);
    int t;
    for (int i = 1; i < n; i++) {
        cin >> t;
        if (t == -1)
            g[0].push_back(i);
        else
            g[t].push_back(i);
    }
    int result = 0;
    for (auto i : g[0]) {
        result = max(result, dfs(i));
    }
    cout << result;
    return 0;
}