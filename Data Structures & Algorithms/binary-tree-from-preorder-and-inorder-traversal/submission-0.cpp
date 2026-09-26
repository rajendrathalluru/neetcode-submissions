class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        
        return build(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int& preIndex, int left, int right) {
        
        // No elements in this subtree
        if (left > right) {
            return nullptr;
        }
        
        // First element in preorder is the root
        int rootValue = preorder[preIndex];
        preIndex++;
        
        TreeNode* root = new TreeNode(rootValue);
        
        // Find root in inorder
        int rootIndex = left;
        while (inorder[rootIndex] != rootValue) {
            rootIndex++;
        }
        
        // Build left subtree
        root->left = build(preorder, inorder, preIndex,
                           left, rootIndex - 1);
        
        // Build right subtree
        root->right = build(preorder, inorder, preIndex,
                            rootIndex + 1, right);
        
        return root;
    }
};