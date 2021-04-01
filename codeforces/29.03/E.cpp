#include <iostream>

using namespace std;

int main() {
    int n, t, count0=0, count1=0, max0=-1;
    cin >> n;
    while (n--) {
        cin >> t;
        if (t) {
            count1++;
            if (count0) count0--;
        } else {
            count0++;
            if (count0 > max0) max0 = count0;
        }
    }
    cout<<count1 + max0;
    return 0;
}
