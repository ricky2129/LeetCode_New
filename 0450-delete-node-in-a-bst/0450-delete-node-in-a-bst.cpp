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
    int maxVal(TreeNode* root){
        TreeNode* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //if root hi NULL hai 
        if(root==NULL){
            return NULL;
        }

        if(root->val==key){
            //4 cases
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            else if (root->left==NULL && root->right!=NULL){
                return root->right;
            }
            else if (root->left!=NULL && root->right==NULL){
                return root->left;
            }
            else{
                int inorderPre=maxVal(root->right);
                root->val=inorderPre;
                root->right=deleteNode(root->right,inorderPre);
                return root;
            }
        }

        else if(key > root->val){
            root->right=deleteNode(root->right,key);
        }

        else if(key < root->val){
            root->left=deleteNode(root->left,key);
        }

        return root;
        
    }
};