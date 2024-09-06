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
    vector<TreeNode*>ans;
    unordered_map<string , int>subTreeMap;

    string preOrder(TreeNode* root){
        if(!root){
            return "N";
        }

        string curr=to_string(root->val);
        string l=preOrder(root->left);
        string r=preOrder(root->right);
        string s=curr+","+l+","+r;

        if(subTreeMap.find(s)!=subTreeMap.end()){
            if(subTreeMap[s]==1){
                ans.push_back(root);
            }
            subTreeMap[s]++;
        }
        else{
            subTreeMap[s]=1;
        }

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       preOrder(root) ;
       return ans;
    }
};