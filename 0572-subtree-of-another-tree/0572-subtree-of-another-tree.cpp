class Solution {
public:
    // Helper function to check if two trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (root == nullptr) {
            return false;
        }

        // Check if the current trees are identical
        if (isSameTree(root, subroot)) {
            return true;
        }

        // Otherwise, check the left and right subtrees
        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
    
};