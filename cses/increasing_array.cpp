// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;

int main() {
    stringstream ss;
    ss << cin.rdbuf();
    size_t n;
    ss >> n;
    int64_t lower_limit;
    ss >> lower_limit;
    int64_t moves = 0;
    for (size_t i = 1; i < n; i++) {
        int64_t num;
        ss >> num;
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