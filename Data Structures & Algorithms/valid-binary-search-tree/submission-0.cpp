class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
    
    bool check(TreeNode* node, long minValue, long maxValue) {
        if (node == nullptr) {
            return true;
        }
        
        if (node->val <= minValue || node->val >= maxValue) {
            return false;
        }
        
        return check(node->left, minValue, node->val) &&
               check(node->right, node->val, maxValue);
    }
};