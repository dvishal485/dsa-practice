// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n;
    cin >> n;
    int64_t lower_limit;
    cin >> lower_limit;
    int64_t moves = 0;
    for (size_t i = 1; i < n; i++) {
        int64_t num;
        cin >> num;
        int64_t difference = lower_limit - num;
        if (lower_limit > num) {
            moves += difference;
        } else {
            lower_limit = num;
        }
    }
    cout << moves << endl;
    return 0;
}