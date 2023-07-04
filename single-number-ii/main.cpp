#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define main_start int main(void)
// datatypes
#define i32 int32_t
#define u32 uint32_t
#define i64 int64_t
#define u64 uint64_t
#define usize size_t
// vector print
template <typename T>
void print_vec(vector<T> const& v) {
    std::copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
}

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int once = 0;
        int twice = 0;
        for (auto const& n : nums) {
            // consider the bits which came 3 times
            // came twice & (came once or incoming)
            int thrice = (once | n) & twice;
            // update bits which came twice (came once and incoming)
            twice |= once & n;
            // remove bits from twice which came thrice
            twice ^= thrice;
            // update once (xor make a number die if twice)
            once ^= n;
            // update once by removing num which came thrice
            // so once now will only have bit which came
            // exactly once
            once ^= thrice;
        }
        // since once stored num which came
        // exactly once so, simply return it
        return once;
    }
};