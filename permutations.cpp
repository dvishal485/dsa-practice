// https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
using namespace std;

int main() {
    uint n;
    cin >> n;
    if (n == 3 || n == 2) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (uint i = 2; i <= n; i += 2) {
        cout << i << " ";
    }
    for (uint i = 1; i <= n; i += 2) {
        cout << i << " ";
    }

    return 0;
}