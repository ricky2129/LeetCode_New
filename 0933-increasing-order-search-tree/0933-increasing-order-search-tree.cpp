class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyNode = new TreeNode(0); // Dummy node to hold the new tree
        TreeNode* current = dummyNode; // Pointer to keep track of the right child

        // Helper function to perform in-order traversal
        inOrderTraversal(root, current);

        return dummyNode->right; // Return the right child of the dummy node, which is the new root
    }
    
    void inOrderTraversal(TreeNode* node, TreeNode*& current) {
        if (!node) return;

        // Traverse the left subtree
        inOrderTraversal(node->left, current);

        // Process the current node
        current->right = node; // Set the current node's right to the new node
        node->left = nullptr;  // Set the current node's left to null (as required)
        current = current->right; // Move current pointer to the newly added node

        // Traverse the right subtree
        inOrderTraversal(node->right, current);
    }
};