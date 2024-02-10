class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
       int i=-1,j=0;
       for(int k=0;k<nums.size();k++){
           if(nums[k]<0) i=k;
       }
       j=i+1;
        
        while(i>=0 && j<nums.size()){
            if(-1*nums[i]>=nums[j]){
                ans.push_back(nums[j]*nums[j]); j++;
            }
            else {
                ans.push_back(nums[i]*nums[i]); i--;
            }
        }
        while(j<nums.size()){
            ans.push_back(nums[j]*nums[j]); j++;
        }
        while(i>=0){
            ans.push_back(nums[i]*nums[i]); i--;
        }
        return ans;
    }
};