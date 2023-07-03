#include <bits/stdc++.h>

#include <algorithm>
#include <numeric>

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
    int generate_k(vector<int> const& nums, const int target_max) {
        int res = 0;

        int curr_sum = 0;
        for (auto const& n : nums) {
            if (curr_sum + n <= target_max) {
                curr_sum += n;
            } else {
                res += 1;
                curr_sum = n;
            }
        }
        res += curr_sum > 0;
        return res;
    }
    int splitArray(vector<int>& nums, int k) {
        // gives minimum k
        int max_sum = accumulate(nums.begin(), nums.end(), 0);
        // gives maximum k
        int min_sum = *max_element(nums.begin(), nums.end());
        int l = min_sum, r = max_sum;
        while (l < r) {
            int mid = (l + r) >> 1;
            auto k_obtained = generate_k(nums, mid);
            if (k_obtained > k) {
                // we are towards maximum k, move right
                l = mid + 1;
            } else {
                // every answer is a candidate answer,
                // we have to minimize that candidate answer
                r = mid;
            }
        }
        return l;
    }
};