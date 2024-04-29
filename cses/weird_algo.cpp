// https://cses.fi/problemset/task/1068
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long unsigned x;
    cin >> x;
    while (x != 1) {
        cout << x << " ";
        if (x & 1) {
            x = 3 * x + 1;
        } else {
            x = x / 2;
        }
    }
    cout << 1;
    return 0;
}