#include <bits\stdc++.h>

using namespace std;

template<typename T>
void print_queue(T q) { 
    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.top();
        cout << x << " " << y << " ";
        q.pop();
    }
    std::cout << '\n';
}

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(150, 0));
    pq.push(make_pair(5, 0));
    pq.push(make_pair(3, 0));
    pq.push(make_pair(2, 0));
    print_queue(pq);
    // for (int i = 0; i < 4; i++) {
    //     pair<int, int> t = pq.top();
    //     pq.pop();
    //     cout << t.first << " " << t.second << "\n";
    // }
    
    return 0;
}