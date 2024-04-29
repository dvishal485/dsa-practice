// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
using namespace std;
#define u128 long long unsigned

const u128 MOD = 1e9 + 7;

u128 solve(uint n, vector<u128> &dp) {
    u128 &moves = dp[n];
    if (moves != 0) {
        return moves;
    }

    const uint max_dice_move = min(n, (uint)6);
    for (uint dice = 1; dice <= max_dice_move; dice++) {
        moves = (moves + solve(n - dice, dp)) % MOD;
    }

    return moves;
}

int main() {
    uint n;
    cin >> n;

    vector<u128> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    auto res = solve(n, dp);
    cout << res << endl;

    return 0;
}
