/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode*& temp,TreeNode* cloned,TreeNode* target){
        if(!cloned){
            return;
        }
        if(cloned->val==target->val){
            temp=cloned;
            return;
        }
        solve(temp,cloned->left,target);
        solve(temp,cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* temp;
        solve(temp,cloned,target);

        return temp;

    }
    
};