/*
ID: deadly51
TASK: pprime
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i+=2)
        if (n % i == 0) return false;
    return true;
}


void Solve() {

    
}


void SolveInit(int a, int b) {

}

int main() {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    int a, b;
    fin >> a >> b;
    SolveInit(int a, int b);
    return 0;
}