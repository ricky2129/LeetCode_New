class Solution {
public:
    void solveRE(int i,vector<int>&nums, vector<int>& ans, vector<vector<int>>& result) {
            if (i>=nums.size()){
                result.push_back(ans);
                return ;
            }
            ans.push_back(nums[i]);
            solveRE(i+1,nums,ans,result);
            ans.pop_back();
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
            solveRE(i+1,nums,ans,result);
            
            
           
            // solveRE(i+1,nums,ans,result);
            
            

        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        solveRE(0, nums, ans, result); // Start recursion with the number 1
        return result;
    }
};