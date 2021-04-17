/*
ID: deadly51
PROG: ariprog
LANG: C++11
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct result {
    int a;
    int b;
    bool operator<(const result& input) const {
        if (input.b != b)
            return b < input.b;
        else
            return a < input.a;
    }
};


int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int n, m;
    fin >> n >> m;

    int size_max = m*m*2;
    vector<int> map(size_max+1, 0);
    set<int> collection;

    for (int p = 0; p <= m; p++)
        for (int q = 0; q <= m; q++)
            collection.insert(p*p+q*q);

    int last = 0;
    for (int a : collection) {
        map[last] = a - last;
        last = a;
    }
    map[0] = 1;
    map[last] = 1;

    vector<result> ret;

    for (int a : collection) {
        for (int b = map[a]; b <= (size_max - a) / (n - 1) + 1; b++) {
            int cur = a;
            bool flag = true;
            for (int i = 1; i < n; ++i) {
                cur += b;
                if (map[cur] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result r = {a, b};
                ret.push_back(r);
            }
        }
    }

    if (ret.size() == 0) {
        fout << "NONE" << endl;
    } else {
        sort(ret.begin(), ret.end());
        for (result& r : ret) {
            fout << r.a << " " << r.b << endl;
        }
    }
    return 0;
}