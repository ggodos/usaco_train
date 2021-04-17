/*
ID: deadly51
PROG: milk3
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int A, B, C;
int CB[21][21];


void search(int c, int b) {
    int a;
    if (CB[c][b] == 1) return;
    CB[c][b] = 1;
    a = C-b-c;
    if(A < b+a)
        search(c, b - (A - a));
    else
        search(c, 0);
    if(A < c+a)
        search(c - (A - a), b);
    else
        search(0, b);
    if(B < c+b)
        search(c - (B - b), B);
    else
        search(0, c + b);
    if(B < a+b)
        search(c, B);
    else
        search(c, b + a);
    if(C < b+c)
        search(C, b - (C - c));
    else
        search(c + b, 0);
    if(C < a+c)
        search(C, b);
    else
        search(c + a, b);
}


int main() {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    fin >> A >> B >> C;
    search(C, 0);

    for (int i = 0; i <= C; i++) {
        if (CB[i][C-i] == 1) {
            if (i != C-B && i != 0)
                fout << " ";
            fout << i;
        }
    }
    fout << "\n";
    return 0;
}
