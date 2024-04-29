// https://leetcode.com/problems/open-the-lock
#include <bits/stdc++.h>
using namespace std;

const int power_ten[] = {1, 10, 100, 1000};

class Solution {
  public:
    int openLock(vector<string> &deadends, string target) {
        bool dead[10000];

        fill_n(dead, 10000, false);

        for (auto const &e : deadends) {
            int idx = stoi(e);
            if (idx == 0)
                return -1;
            dead[idx] = true;
        }

        int res = rotate(dead, stoi(target));

        return res;
    }
    int rotate(bool *dead, const int target) {
        queue<int> dials;

        int move_id = 0;
        dials.push(0);
        dead[0] = true;

        while (!dials.empty()) {
            const int moves = dials.size();
            for (int i = 0; i < moves; i++) {
                auto curr = dials.front();
                if (curr == target) {
                    return move_id;
                }

                for (int pos = 0; pos < 4; pos++) {
                    // try rotate dial pos

                    // int place_val = (int)pow(10, pos);
                    int place_val = power_ten[pos];

                    int decimal_bit = (curr / place_val) % 10;

                    int curr_1 = decimal_bit < 9
                                     ? curr + place_val
                                     : curr - decimal_bit * place_val;
                    if (!dead[curr_1]) {
                        dead[curr_1] = true;
                        dials.push(curr_1);
                    }

                    int curr_2 = decimal_bit > 0 ? curr - place_val
                                                 : curr + 9 * place_val;
                    // cout << "lets rotate (dec) dial " << pos << " (" <<
                    // place_val <<
                    // ")"
                    //      << " from the val " << curr
                    //      << " to " << curr_2 << endl;

                    if (!dead[curr_2]) {
                        dead[curr_2] = true;
                        dials.push(curr_2);
                    }
                }

                dials.pop();
            }
            move_id++;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";

    cout << s.openLock(deadends, target) << endl;
}
