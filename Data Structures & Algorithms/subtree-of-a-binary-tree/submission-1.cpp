class Solution {
public:
    bool issametree(TreeNode* root, TreeNode* subRoot) {

        if (root == nullptr && subRoot == nullptr) {
            return true;
        }

        if (root == nullptr || subRoot == nullptr) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        return issametree(root->left, subRoot->left) &&
               issametree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (subRoot == nullptr) {
            return true;
        }

        if (root == nullptr) {
            return false;
        }

        // Check whether subtree starts HERE
        if (issametree(root, subRoot)) {
            return true;
        }

        // Otherwise SEARCH left and right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};