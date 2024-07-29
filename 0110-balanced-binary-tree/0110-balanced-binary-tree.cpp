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
int maxDepth(TreeNode* root) {
        //base case
        if(root==NULL){
            return 0;
        }

        return max(maxDepth(root->left),maxDepth(root->right)) +1;
        
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        int x=abs(left-right);
         bool ans1= (x<=1);

         bool leftAns=isBalanced(root->left);
         bool rightAns=isBalanced(root->right);

         if(ans1 && leftAns && rightAns){
            return true;
         }
         return false;
    }
};