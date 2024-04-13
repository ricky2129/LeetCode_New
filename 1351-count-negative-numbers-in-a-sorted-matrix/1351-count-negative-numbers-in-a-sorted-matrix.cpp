class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n=grid[0].size();
        int m=grid.size();

        int row=0,col=n-1;
        
        while(row < m && col>=0){
            if(grid[row][col] < 0){
                count+= (m-row);

                col--;
            }
            else{
                row++;
            }
        }
        return count;
        
    }
};