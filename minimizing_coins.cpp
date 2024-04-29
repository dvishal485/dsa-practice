// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

vector<uint> coins;
vector<int> dp;

int solve(uint target) {
    int &sol = dp[target];
    if (sol != INT_MAX) {
        return sol;
    }
    for (auto coin : coins) {
        if (target == coin) {
            return sol = 1;
        }
        if (target > coin) {
            int res = solve(target - coin);
            if (res != -1) {
                sol = min(sol, 1 + res);
            }
        }
    }
    return sol = (sol == INT_MAX ? -1 : sol);
}

int main() {
    uint n, target;
    cin >> n >> target;
    coins.reserve(n);
    dp = vector<int>(target + 1, INT_MAX);

    for (uint i = 0; i < n; i++) {
        uint coin;
        cin >> coin;
        coins.emplace_back(coin);
    }

    sort(coins.begin(), coins.end(), std::greater<uint>());
    int res = solve(target);
    cout << res << endl;
    return 0;
}