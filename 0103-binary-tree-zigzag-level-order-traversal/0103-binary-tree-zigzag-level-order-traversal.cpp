
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    bool LtoR=true;
    if(!root) return ans;
    queue<TreeNode* >q;
    q.push(root);

    while(!q.empty()){
        int width=q.size();
        vector<int>result(width);
        for(int i=0;i<width;i++){
            TreeNode* front=q.front();q.pop();
            int index =LtoR? i:width-i-1;
            result[index]=front->val;

            if(front->left){
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }

        }
        LtoR=!LtoR;
        ans.push_back(result);
    }
    return ans;
    }
};