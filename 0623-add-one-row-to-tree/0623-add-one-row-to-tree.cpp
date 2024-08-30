class Solution {
public:
    void solve(TreeNode* root, int val, int depth, int currentDepth) {
        
        if (root == nullptr) {
            return;
        }

        
        if (currentDepth == depth ) {
            // Create new nodes with the given value
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

     
            newLeft->left = root->left;
            newRight->right = root->right;

            root->left = newLeft;
            root->right = newRight;

            return;
        }

       
        solve(root->left, val, depth, currentDepth + 1);
        solve(root->right, val, depth, currentDepth + 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        depth=depth-1;
        if (depth == 0) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // Call the helper function starting from depth 1
        solve(root, val, depth, 1);

        return root;
    }
};