
class Solution {
public:
    int m, n;
    vector<vector<int>> pacific, atlantic;

    vector<vector<int>> dirs = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<int>>& visited) {

        visited[r][c] = 1;

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (visited[nr][nc])
                continue;

            // Reverse flow: move to equal or higher cells.
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        pacific.assign(m, vector<int>(n, 0));
        atlantic.assign(m, vector<int>(n, 0));

        // Pacific: top row and left column.
        for (int c = 0; c < n; c++)
            dfs(0, c, heights, pacific);

        for (int r = 0; r < m; r++)
            dfs(r, 0, heights, pacific);

        // Atlantic: bottom row and right column.
        for (int c = 0; c < n; c++)
            dfs(m - 1, c, heights, atlantic);

        for (int r = 0; r < m; r++)
            dfs(r, n - 1, heights, atlantic);

        vector<vector<int>> result;

        // Find cells reachable from both oceans.
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
