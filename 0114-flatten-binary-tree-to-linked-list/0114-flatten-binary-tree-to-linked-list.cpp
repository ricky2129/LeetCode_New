class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        
        // Flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);
        
        // Store the left and right subtrees
        TreeNode* templeft = root->left;
        TreeNode* tempright = root->right;
        
        // Move the left subtree to the right
        root->right = templeft;
        root->left = nullptr;
        
        // Find the rightmost node of the new right subtree
        TreeNode* curr = root;
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        
        // Attach the original right subtree
        curr->right = tempright;
    }
};