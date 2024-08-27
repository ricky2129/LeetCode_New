class Solution {
public:
    void solve(TreeNode* root, long long targetSum, long long currSum, int& count) {
        if (root == NULL) {
            return;
        }

        // Include current node
        currSum += root->val;

        // If current sum equals targetSum, increment the count
        if (currSum == targetSum) {
            count++;
        }

        // Recur for left and right subtrees
        solve(root->left, targetSum, currSum, count);
        solve(root->right, targetSum, currSum, count);
    }

    int pathSum(TreeNode* root, long long targetSum) {
        if (root == NULL) {
            return 0;
        }

        int count = 0;
        
        // Perform a DFS starting from the current node
        solve(root, targetSum, 0, count);
        
        // Recursively check paths starting from the left and right child nodes
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};