/*
ID: deadly51
TASK: numtri
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    int n;
    fin >> n;
    vector<vector<int>> piramid(n);
    for (int i = 1; i <= n; i++) {
        piramid[i-1].resize(i);
        for (int j = 0; j < i; j++)
            fin >> piramid[i-1][j];
    }
    int res = 0;
    int min = pow(2, n-1);
    for (int i = min; i < min*2; i++) {
        int sum = 0;
    }
    
    fout << res << "\n";
    return 0;
}