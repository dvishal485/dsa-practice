// https://leetcode.com/problems/freedom-trail/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findRotateSteps(string ring, string key) {
        const size_t m = ring.size();
        const size_t n = key.size();
        vector<vector<int>> dp(m, vector<int>(n, INT16_MAX));
        int res = find_press(ring, key, dp);
        return res;
    }

    int find_press(const string &ring, const string &key,
                   vector<vector<int>> &dp, int start = 0, int ring_ptr = 0) {
        if (start >= key.size()) {
            return 0;
        }

        int &res = dp[ring_ptr][start];
        if (res != INT16_MAX) {
            return res;
        }

        const char target = key[start];
        const char me = ring[ring_ptr];

        if (me == target) {
            // always press it greedily caz it takes 1 move anyway
            res = 1 + find_press(ring, key, dp, start + 1, ring_ptr);
            return res;
        }

        const int limit = ring.size() / 2 + 1;

        for (int turn = 1; turn < limit + 1; turn++) {
            // fix ring_ptr
            int new_ring_ptr = (ring_ptr + turn) % ring.size();
            if (ring[new_ring_ptr] == target) {
                int sol = turn + find_press(ring, key, dp, start, new_ring_ptr);
                res = min(res, sol);
            }
        }
        for (int turn = 1; turn < limit + 1; turn++) {
            // fix ring_ptr
            int new_ring_ptr = (ring_ptr - turn + ring.size()) % ring.size();
            if (ring[new_ring_ptr] == target) {
                int sol = turn + find_press(ring, key, dp, start, new_ring_ptr);
                res = min(res, sol);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    string ring = "kqqwb";
    string key = "wwwqqqqqqkkkbbb";
    int soln = s.findRotateSteps(ring, key);
    cout << soln << endl;
    return 0;
}