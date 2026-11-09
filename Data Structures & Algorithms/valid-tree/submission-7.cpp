
class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A valid tree must have exactly n-1 edges
        if (edges.size() != n - 1) {
            return false;
        }

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        // Start DFS from node 0
        dfs(0, adj, visited);

        // Check connectivity
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};
