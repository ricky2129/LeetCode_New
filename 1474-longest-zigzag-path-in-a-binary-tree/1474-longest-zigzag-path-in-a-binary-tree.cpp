/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int count = 0; // To store the maximum ZigZag path length

    void solve(TreeNode* root, int length, bool isLeft) {
        if (!root) return;  // Base case: if the current node is null, return
        
        // Update the maximum length of the ZigZag path
        count = max(length, count);

        // If the last move was left, the next move should be right, and vice versa
        if (isLeft) {
            // If the last move was left, try moving right
            solve(root->right, length + 1, false);
            // Restart the path from the left child, if it exists
            solve(root->left, 1, true);
        } else {
            // If the last move was right, try moving left
            solve(root->left, length + 1, true);
            // Restart the path from the right child, if it exists
            solve(root->right, 1, false);
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0; // If the tree is empty, return 0

        // Start from both left and right directions from the root
        if (root->left) {
            solve(root->left, 1, true); // Start moving left
        }
        if (root->right) {
            solve(root->right, 1, false); // Start moving right
        }

        return count; // Return the maximum ZigZag path length found
    }
};