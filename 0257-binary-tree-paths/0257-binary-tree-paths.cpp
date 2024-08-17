class Solution {
public:
    void solve(TreeNode* root, vector<string>& result, string ans) {
        if (root == nullptr) {
            return; // If the node is null, just return
        }
        
        // Append current node's value to the path
        if (!ans.empty()) {
            ans += "->";
        }
        ans += to_string(root->val);
        
        // If it's a leaf node, add the path to the result
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(ans);
            return;
        }
        
        // Recur for left and right subtrees
        solve(root->left, result, ans);
        solve(root->right, result, ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string ans = "";
        solve(root, result, ans);
        return result;
    }
};