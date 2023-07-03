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
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> seen_remainder;
        // zero is a valid sum, which can be seen in subarray
        // at very start [], lets give it index 0 and follow
        // 1-based indexing
        seen_remainder.insert({0, 0});
        int prefix_sum = 0;
        // basically the concept is, if any two sub array have save remainder,
        // they cancel out each other and hence a valid answer
        for (int i = 0; i < n; i++) {
            prefix_sum = (prefix_sum + nums[i]) % k;
            auto seen = seen_remainder.insert({prefix_sum, i + 1});

            if (!seen.second) {
                // remainder was encountered before
                auto val = (seen.first)->second;
                // remainder len is atleast [i-1..i+1]
                if (val < i) return true;
            }
        }
        return false;
    }
};