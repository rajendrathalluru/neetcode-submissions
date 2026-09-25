class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int answer = 0;
        
        inorder(root, k, count, answer);
        
        return answer;
    }
    
    void inorder(TreeNode* node, int k, int& count, int& answer) {
        if (node == nullptr) {
            return;
        }
        
        // Left
        inorder(node->left, k, count, answer);
        
        // Current node
        count++;
        
        if (count == k) {
            answer = node->val;
            return;
        }
        
        // Right
        inorder(node->right, k, count, answer);
    }
};