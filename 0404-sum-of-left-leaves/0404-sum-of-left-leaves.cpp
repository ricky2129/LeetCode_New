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
    void  solve(TreeNode* root , bool flag,int &sum){
         if (root == nullptr) return;
        if(root->left==NULL && root->right==NULL){
            if(flag && root!= NULL){
                sum+=root->val;
            }
            return;
        }
        solve(root->left,true,sum);
        solve(root->right,false,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        solve(root,false,sum);
        return sum;
    }
};