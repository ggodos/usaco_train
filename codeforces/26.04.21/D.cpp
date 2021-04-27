#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> w(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];
        int res = 0;
        for (int i = n-1; i >= 0; i--) {
            w[i] = v[i];
            if (i + v[i] < n) w[i] += w[i + v[i]];
        }
        for (auto z : w) res = max(res, z);
        cout << res << "\n";
    }
    return 0;
}