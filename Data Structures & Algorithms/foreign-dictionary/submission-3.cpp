
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize all unique characters
        for (string &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // Build graph by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i];
            string b = words[i + 1];

            int len = min(a.size(), b.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    if (adj[a[j]].insert(b[j]).second) {
                        indegree[b[j]]++;
                    }
                    found = true;
                    break;
                }
            }

            // Invalid prefix case
            if (!found && a.size() > b.size()) {
                return "";
            }
        }

        // Topological sort using BFS
        queue<char> q;

        for (auto &[c, degree] : indegree) {
            if (degree == 0) {
                q.push(c);
            }
        }

        string result;

        while (!q.empty()) {
            char c = q.front();
            q.pop();

            result += c;

            for (char next : adj[c]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If not all characters processed, graph has a cycle
        return result.size() == indegree.size() ? result : "";
    }
};
