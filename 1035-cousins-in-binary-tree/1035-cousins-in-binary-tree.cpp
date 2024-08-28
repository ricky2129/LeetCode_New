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

    TreeNode* Par_x,*Par_y;
    int Depth_x,Depth_y ;

    void dfs(TreeNode* a,TreeNode* Par,int Depth, int x, int y)
    {
        if(!a)return;
         
        if(a->val==x){
            Depth_x=Depth; Par_x=Par;
        }
        if(a->val==y){
            Depth_y=Depth; Par_y=Par;
        }

        dfs(a->left,a,Depth+1,x,y);
        dfs(a->right,a,Depth+1,x,y);

    }

public:

    bool isCousins(TreeNode* a,int x, int y) {
        dfs(a,nullptr,0,x,y);
        return (Depth_x==Depth_y && Par_x!=Par_y);
    }
};