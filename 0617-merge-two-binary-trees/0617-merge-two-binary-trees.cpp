class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // If either of the trees is NULL, return the other tree
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        // Merge the values of the current nodes
        root1->val += root2->val;

        // Recursively merge the left and right subtrees
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};