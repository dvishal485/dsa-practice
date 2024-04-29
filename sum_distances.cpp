#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
     Node *parent;
    vector<Node> children;
};

class Solution {
    vector<int> weights;
    vector<vector<int>> adj;

  public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        adj = vector<vector<int>>(n, vector<int>());
        for (auto &edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        // now lets give every node a global weight wrt pseudo root (0)
        init_weights(n);

        // now that i have given weights, i can just apply magic formula
        return {};
    }

    int distance(int node1, int node2) { return 0; }

    void init_weights(int n) {
        weights = vector<int>(n, 0);
        queue<pair<int, int>> q;
        q.emplace(0, -1); // me, parent

        int gen = 0;
        while (!q.empty()) {
            const size_t gen_len = q.size();
            for (size_t i = 0; i < gen_len; i++) {
                auto [me, parent] = q.front();
                weights[me] = gen;

                for (auto child : adj[me]) {
                    if (child != parent) {
                        q.emplace(child);
                    }
                }

                q.pop();
            }
            gen += 1;
        }
    }
};

int main() { return 0; }