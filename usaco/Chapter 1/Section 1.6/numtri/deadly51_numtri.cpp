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
    vector<vector<int>> input(n);
    for (int i = 1; i <= n; i++) {
        input[i-1].resize(i);
        for (int j = 0; j < i; j++)
            fin >> input[i-1][j];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            input[i][j] += max(input[i+1][j], input[i+1][j+1]);
        }
    }
    
    fout << input[0][0] << "\n";
    return 0;
}