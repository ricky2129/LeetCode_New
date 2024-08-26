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
    void solve(TreeNode* root, int& sum , int digits){
        //base case
        if(root==NULL){
            
            return ;
        }
        digits=digits*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=digits;
            return ;
        }
        solve(root->left,sum,digits);
        solve(root->right,sum,digits);

    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int digits=0;
        solve(root,sum,digits);
        return sum;
    }
};