class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        
        maxGain(root, result);
        
        return result;
    }
    
    int maxGain(TreeNode* node, int& result) {
        if (node == nullptr) {
            return 0;
        }
        
        // Ignore negative paths
        int leftGain = max(0, maxGain(node->left, result));
        int rightGain = max(0, maxGain(node->right, result));
        
        // Path passing through current node
        int currentPath = node->val + leftGain + rightGain;
        
        result = max(result, currentPath);
        
        // Return only one side to the parent
        return node->val + max(leftGain, rightGain);
    }
};