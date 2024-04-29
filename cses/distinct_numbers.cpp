// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<int64_t> nums;
    nums.reserve(n);
    for (size_t i = 0; i < n; i++) {
        int64_t num;
        cin >> num;
        nums.emplace_back(num);
    }

    sort(nums.begin(), nums.end());

    int64_t prev_num = nums[0];
    int64_t count = 1;
    for (auto num : nums) {
        if (num != prev_num) {
            count += 1;
            prev_num = num;
        }
    }
    cout << count << endl;

    return 0;
}