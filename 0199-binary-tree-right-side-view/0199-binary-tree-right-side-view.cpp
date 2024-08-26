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
    void solve(TreeNode* root,vector<int>& rightview,int level){
        if(root==NULL){
            return;
        }

        if(level==rightview.size()){
            rightview.push_back(root->val);
        }

        solve(root->right,rightview,level+1);
        solve(root->left,rightview,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        vector<int>rightview;
        solve(root,rightview,level);
        return rightview;
    }
};