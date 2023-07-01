#include <bits/stdc++.h>

#include <cassert>

using namespace std;

#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define main_start int main(void)
// datatypes
#define i32 int
#define u32 unsigned i32
#define i64 long long
#define u64 unsigned i64
#define usize size_t
// vector print
template <typename T>
void print_vec(vector<T> const& v) {
    std::copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
}

// this is a very ugly and hacky soln
#define return_memo return dp[s_idx * ps + p_idx] =
class Solution {
   public:
    bool isMatch(string s, string p) {
        vector<i32> dp((s.size() + 1) * (p.size() + 1), -1);
        return isMatch(s, p, 0, 0, dp);
    }
    bool isMatch(string& s, string& p, int s_idx, int p_idx, vector<i32>& dp) {
        const int ss = s.size();
        const int ps = p.size();
        if (s_idx == ss && p_idx == ps) return true;
        if (p_idx == ps) return false;
        if (dp[s_idx * ps + p_idx] != -1) return dp[s_idx * ps + p_idx];
        if (s_idx == ss) {
            if ((ps - p_idx) & 1) return_memo false;
            for (int i = p_idx; i < ps; i = i + 2) {
                if (p[i + 1] != '*') return_memo false;
            }
            return_memo true;
        }

        if (p_idx + 1 < ps && p[p_idx + 1] == '*') {
            // this is (to_match)*
            char to_match = p[p_idx];
            bool res = isMatch(s, p, s_idx, p_idx + 2, dp);
            if (res) return_memo true;
            for (int i = s_idx; i < ss; i++) {
                if (to_match != '.' && s[i] != to_match) break;
                if (isMatch(s, p, i + 1, p_idx + 2, dp)) {
                    res = true;
                    break;
                }
            }
            return_memo res;
        }
        return_memo(p[p_idx] == '.' || s[s_idx] == p[p_idx]) &&
            isMatch(s, p, s_idx + 1, p_idx + 1, dp);
    }
};