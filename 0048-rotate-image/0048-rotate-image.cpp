class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> res(n, vector<int>(n,0));
        for(int j=matrix.size()-1;j>=0;j--){
            for(int i=0;i<matrix.size();i++){
                res[i][j]=matrix[j][i];
            }
        }
        matrix=res;
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};