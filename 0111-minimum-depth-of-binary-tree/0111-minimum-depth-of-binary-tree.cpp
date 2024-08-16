class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // If left subtree is NULL, recurse on right subtree
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }

        // If right subtree is NULL, recurse on left subtree
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }

        // If neither subtree is NULL, take the minimum of the two depths
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};