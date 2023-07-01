#include <bits/stdc++.h>

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

class Solution {
   public:
    string longestPalindrome(string s) {
        const int n = s.size();
        i32 best_slice_len = 1;  // min ans possible is 1, as n >= 1
        i32 best_slice_start = 0;

        i32 window_start = 0;
        i32 window_end = 1;
        while (window_end < n) {
            i32 start = window_start;
            i32 end = window_end;
            // two ki window
            while (start >= 0 && end < n && s[start] == s[end]) start--, end++;

            // flush the answer
            i32 slice_len = end - start - 1;
            if (best_slice_len < slice_len)
                best_slice_start = start + 1, best_slice_len = slice_len;

            // three ki window
            start = window_start++;
            end = ++window_end;
            // flush the answer
            while (start >= 0 && end < n && s[start] == s[end]) start--, end++;

            // flush the answer
            slice_len = end - start - 1;
            if (best_slice_len < slice_len)
                best_slice_start = start + 1, best_slice_len = slice_len;
        }
        s.erase(best_slice_start + best_slice_len);
        s.erase(0, best_slice_start);

        return s;
    }
};

// #LCEND https://leetcode.com/problems/longest-palindromic-substring/
main_start { fast; }
