// https://leetcode.com/problems/number-of-wonderful-substrings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long wonderfulSubstrings(string word) {
        unordered_map<bitset<10>, uint> freq;
        bitset<10> running_mask(0);
        long long res = 0;

        freq[0] = 1;
        for (auto c : word) {
            const size_t idx = c - 'a';
            running_mask.flip(idx);
            // no odd char
            res += freq[running_mask];
            freq[running_mask] += 1;
            // 1 odd char
            for (size_t i = 0; i < 10; i++) {
                running_mask.flip(i);
                res += freq[running_mask];
                running_mask.flip(i);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    auto res = s.wonderfulSubstrings("aabbaaba");
    cout << res << endl;
    return 0;
}