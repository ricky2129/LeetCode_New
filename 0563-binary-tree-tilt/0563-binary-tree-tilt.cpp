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
    int sumAndTilt(TreeNode* root, int &tiltSum) {
        if (root == nullptr) {
            return 0;
        }
        
        // Calculate sum of left and right subtrees
        int leftSum = sumAndTilt(root->left, tiltSum);
        int rightSum = sumAndTilt(root->right, tiltSum);
        
        // Tilt of the current node
        int tilt = abs(leftSum - rightSum);
        
        // Add the current node's tilt to the total tilt sum
        tiltSum += tilt;
        
        // Return the total sum of the subtree rooted at the current node
        return root->val + leftSum + rightSum;
    }
    int findTilt(TreeNode* root) {
        int tiltSum = 0;
        sumAndTilt(root, tiltSum);
        return tiltSum;
    }
    
   
};