#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        vector<int> degree;
        degree.reserve(n);

        if (n == 1) {
            return {0};
        }

        for (auto &e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        queue<int> leaves;
        vector<int> res;

        for (size_t i = 0; i < n; i++) {
            int deg = adj[i].size();
            degree.push_back(deg);
            if (deg == 1) {
                leaves.emplace(i);
            }
        }

        while (!leaves.empty()) {
            res.clear();
            const size_t leaves_count = leaves.size();
            for (size_t i = 0; i < leaves_count; i++) {
                auto leaf = leaves.front();
                degree[leaf] -= 1;      // killing this node
                res.emplace_back(leaf); // but it is a potential answer
                for (auto &node : adj[leaf]) {
                    degree[node] -= 1; // kill my presence in my parent
                    if (degree[node] == 1) {
                        leaves.emplace(node);
                    }
                }
                leaves.pop();
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> k = {{0, 1}, {1, 2}};
    auto res = s.findMinHeightTrees(3, k);
    return 0;
}