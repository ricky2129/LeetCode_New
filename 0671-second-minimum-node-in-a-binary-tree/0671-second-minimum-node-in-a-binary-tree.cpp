class Solution {
public:
    void findMin(TreeNode* root, long long &mini) {
        if (root == NULL) {
            return; 
        }
        mini = min(mini, (long long)root->val);
        findMin(root->left, mini);
        findMin(root->right, mini);
    }

    void findMin2(TreeNode* root, long long &mini, long long &smin) {
        if (root == NULL) {
            return; 
        }
        if (root->val != mini) {
            smin = min(smin, (long long)root->val);
        }
        findMin2(root->left, mini, smin);
        findMin2(root->right, mini, smin);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long long mini = LLONG_MAX;  // use LLONG_MAX from <climits>
        findMin(root, mini);
        long long smin = LLONG_MAX;
        findMin2(root, mini, smin);

        if (smin == LLONG_MAX) {
            return -1;
        } else {
            return smin;
        }
    }
};