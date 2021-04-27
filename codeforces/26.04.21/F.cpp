#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int v, e, sum = 0, t;
        cin >> v >> e;
        vector<int> prices(v);
        for (int i = 0; i < v; i++) {
            cin >> t;
            sum += t;
        }
        if (v == 2 || e < v) {
            cout << -1 << "\n";
            continue;
        }
        cout << sum * 2 << "\n";
        for (int i = 1; i < v; i++)
            cout << i << " " << i + 1 << "\n";
        cout << v << " " << 1 << "\n";
    }
    return 0;
}