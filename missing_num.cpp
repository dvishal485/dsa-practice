// https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
using namespace std;

uint xor_smart(uint n) {
    uint r = n % 4;
    switch (r) {
    case 0: // [0,1,2,3,4] n=4
        return n;
    case 1: // [0,1,2,3,4,5] n=5
        return 1;
    case 2: // [0,1,2,3,4,5,6] n=6
        return n + 1;
    case 3: // [0,1,2,3,4,5,6,7] n=7
        return 0;
    }
    assert(false);
}

int main() {
    uint n;
    cin >> n;

    uint nums_xor = 0;
    for (uint i = 0; i < n-1; i++) {
        uint temp;
        cin >> temp;
        nums_xor ^= temp;
    }

    cout << (nums_xor ^ xor_smart(n)) << endl;
    return 0;
}