// https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
using namespace std;

int main() {
    uint longest = 0;
    uint streak = 0;
    char c;
    char prev = 0;

    while (cin.get(c)) {
        if (prev == c) {
            streak += 1;
        } else {
            longest = max(longest, streak);
            streak = 1;
        }
        prev = c;
    }

    cout << longest << endl;
    return 0;
}
