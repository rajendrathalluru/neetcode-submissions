class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "#,";
        }
        
        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        
        return buildTree(data, index);
    }
    
    TreeNode* buildTree(string& data, int& index) {
        // Find the next comma
        int comma = data.find(',', index);
        
        string value = data.substr(index, comma - index);
        
        index = comma + 1;
        
        // Null node
        if (value == "#") {
            return nullptr;
        }
        
        // Create node
        TreeNode* node = new TreeNode(stoi(value));
        
        // Build left and right
        node->left = buildTree(data, index);
        node->right = buildTree(data, index);
        
        return node;
    }
};