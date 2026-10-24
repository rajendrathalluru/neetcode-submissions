
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() : word("") {
            memset(children, 0, sizeof(children));
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> result;
    int rows, cols;

    void insertWord(const string& word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node) {

        char ch = board[r][c];

        if (ch == '#') return;

        TrieNode* next = node->children[ch - 'a'];

        if (!next) return;

        // Found a complete word
        if (!next->word.empty()) {
            result.push_back(next->word);
            next->word = "";  // Avoid duplicates
        }

        // Mark cell as visited
        board[r][c] = '#';

        // Explore four directions
        if (r > 0)
            dfs(board, r - 1, c, next);

        if (r + 1 < rows)
            dfs(board, r + 1, c, next);

        if (c > 0)
            dfs(board, r, c - 1, next);

        if (c + 1 < cols)
            dfs(board, r, c + 1, next);

        // Backtrack
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        rows = board.size();
        cols = board[0].size();

        // Build Trie
        for (const string& word : words) {
            insertWord(word);
        }

        // Start DFS from every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }

        return result;
    }
};
