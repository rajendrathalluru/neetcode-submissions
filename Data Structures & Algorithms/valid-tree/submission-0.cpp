
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree must have exactly n - 1 edges
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        // Build undirected graph
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        // DFS
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };

        dfs(0);

        // Check if all nodes are visited
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};
