/*
ID: deadly51
TASK: sprime
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0 ) return false;
    for (int i = 3; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}


int main() {
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    int n;
    fin >> n;
    vector<vector<int>> sp(n);
    sp[0].push_back(1);
    sp[0].push_back(2);
    sp[0].push_back(3);
    sp[0].push_back(5);
    sp[0].push_back(7);
    if (n == 1) {
        fout << "2\n3\n5\n7\n";
        return 0;
    }
    
    for (int i = 1; i < sp[0].size(); i++) {
        for (int j = 1; j < 10; j+=2) {
            int temp = sp[0][i]*10 + j;
            if (prime(temp)) {
                sp[1].push_back(temp);
            }
        }
    }
    if (n == 2) {
        for (auto i : sp[1])
            fout << i << "\n";
        return 0;
    }


    int cur = 2;
    while (cur < n) {
        for (auto i : sp[cur-1]) {
            for (int j = 1; j < 10; j+=2) {
                int temp = i*10 + j;
                if (prime(temp)) {
                    sp[cur].push_back(temp);
                }
            }
        }
        cur++;
    }
    for (auto i : sp[cur-1]) {
        fout << i << "\n";
    }

    return 0;
}