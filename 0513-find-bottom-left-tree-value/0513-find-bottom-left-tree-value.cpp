class Solution {
public:
    void solve(TreeNode* root, int level, int &maxLevel, int &ans) {
        if (root == NULL) {
            return;
        }

        // If we reach a new level that's deeper than any we've seen, update the answer
        if (level > maxLevel) {
            maxLevel = level;
            ans = root->val;
        }

        // Explore the left subtree first to ensure the leftmost node is found first
        solve(root->left, level + 1, maxLevel, ans);
        solve(root->right, level + 1, maxLevel, ans);
    }

    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = -1;  // Start with -1 because the root is at level 0
        int ans = 0;
        solve(root, 0, maxLevel, ans);  // Start at level 0
        return ans;
    }
    
};