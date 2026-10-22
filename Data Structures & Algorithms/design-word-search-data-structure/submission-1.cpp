class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int index) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr &&
                    dfs(node->children[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        }

        int i = c - 'a';

        if (node->children[i] == nullptr) {
            return false;
        }

        return dfs(node->children[i], word, index + 1);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int i = c - 'a';

            if (node->children[i] == nullptr) {
                node->children[i] = new TrieNode();
            }

            node = node->children[i];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};