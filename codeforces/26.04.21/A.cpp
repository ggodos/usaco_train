#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    s--;
    vector<int> to(1001);
    vector<int> from(1001);
    for (int i = 0; i < n; i++)
        cin >> to[i];
    for (int i = 0; i < n; i++)
        cin >> from[i];
    if (!to[0]) {
        cout << "NO";
        return 0;
    }
    if (to[s]) {
        cout << "YES";
        return 0;
    }
    if (!from[s]) {
        cout << "NO";
        return 0;
    }

    int flag = 0;
    for (int i = s; i < n; i++)
        if (to[i] && from[i]) {
            flag = 1;
            break;
        }
    
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}