// https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
using namespace std;

#define uint unsigned long long

void solve(uint x, uint y) {
    uint diagonal = max(x, y);
    /*
    1
    1 + 2 = 3
    1 + 2 + 4 = 7
    1 + 2 + 4 + 6 = 13
    1 + 2 * (1 + 2 + 3 + 4) = 21

    1 + 2 * (((n)(n-1))/2) = 1 + (n)(n-1)
    */
    uint diagonal_elem = 1 + (diagonal) * (diagonal - 1);
    uint delta_y = diagonal - y;
    uint delta_x = diagonal - x;

    if ((diagonal & 1) == 0) {
        uint elem = diagonal_elem + delta_y - delta_x;
        cout << elem << endl;
    } else {
        uint elem = diagonal_elem - delta_y + delta_x;
        cout << elem << endl;
    }
}

int main() {
    size_t t;
    cin >> t;

    for (size_t i = 0; i < t; i++) {
        uint x, y;
        cin >> x >> y;
        solve(x, y);
    }

    return 0;
}