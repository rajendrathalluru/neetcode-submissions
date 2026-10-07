class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int index, int i, int j, int m, int n) {
        // Base case: all characters matched
        if (index == word.length()) {
            return true;
        }

        // Boundary checks and character match check
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }

        // Mark current cell as visited using a temporary placeholder
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 adjacent directions: up, down, left, right
        bool found = dfs(board, word, index + 1, i - 1, j, m, n) ||
                     dfs(board, word, index + 1, i + 1, j, m, n) ||
                     dfs(board, word, index + 1, i, j - 1, m, n) ||
                     dfs(board, word, index + 1, i, j + 1, m, n);

        // Backtrack: restore original character
        board[i][j] = temp;

        return found;
    }
};