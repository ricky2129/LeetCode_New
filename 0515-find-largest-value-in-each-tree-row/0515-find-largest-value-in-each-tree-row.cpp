class Solution {
public:
    void solve(TreeNode* root, int level, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        // If we are at a new level, add the current node's value
        if (level == ans.size()) {
            ans.push_back(root->val);
        } else {
            // Update the largest value at this level
            ans[level] = max(ans[level], root->val);
        }

        // Explore left and right subtrees
        solve(root->left, level + 1, ans);  // Corrected comma instead of semicolon
        solve(root->right, level + 1, ans); // Corrected comma instead of semicolon
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};