class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int>& inorder) {
        if (!root) return;

        // Traverse the left subtree
        inOrderTraversal(root->left, inorder);
        // Process the current node
        inorder.push_back(root->val);
        // Traverse the right subtree
        inOrderTraversal(root->right, inorder);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> inorder;
        int minDiff = INT_MAX;

        // Perform in-order traversal to fill the 'inorder' vector with node values
        inOrderTraversal(root, inorder);

        // Calculate the minimum difference between consecutive values
        for (int i = 0; i < inorder.size() - 1; i++) {
            int diff = inorder[i+1] - inorder[i];
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    }
};