/*
ID: deadly51
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>
#include <ctime>

using namespace std;


struct res {
    int first;
    int step;
    bool operator<(const res& _entry) const {
        return step < _entry.step;
    }
};



int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    int n, m;
    fin >> n >> m;
    fin.close();
    
    set<int> collection;

    for (int p = 0; p <= m; p++)
        for (int q = 0; q <= m; q++)
            collection.insert(p*p + q*q);

    vector<res> sol;
    set<int>::iterator ik;
    unsigned int start_time = clock();
    for (auto i : collection) {
        for (ik=--collection.end(); *ik!=1; ik--) {
            int step = (*ik-i)/(n-1);
            if(step <= 0 || (*ik-i)%(n-1)!=0) continue;
            bool flag = true;
            for (int j=1; j<n; j++) {
                if (collection.find(i+step*j)==collection.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res r = {i, step};
                sol.push_back(r);
            }
        }
    }
    cout << clock() - start_time << endl;
    if (sol.size() == 0)
        fout << "NONE" << endl;
    else {
        sort(sol.begin(), sol.end());
        for (res& r : sol)
            fout << r.first << " " << r.step << endl;
    }
    fout.close();
    return 0;
}


// 37 4
// 5 20

// 0 0
// 1 0