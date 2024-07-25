class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Check if both nodes are null, then they are identical at this level
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one of the nodes is null, and the other is not, they are not identical
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If both nodes are not null, check if their values are the same
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};