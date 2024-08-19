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
    bool solve(TreeNode* root, int val){
        if(root==NULL){
            return true;
        }
        if(root->val!=val){
            return false;
        }

        return solve(root->left,val) && solve(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) {
       if(root==NULL){
        return true;
       }
        return solve(root,root->val);
    }
};