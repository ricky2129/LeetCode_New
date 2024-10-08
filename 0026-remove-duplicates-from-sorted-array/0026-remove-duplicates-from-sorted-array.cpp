class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int num=nums[0] ;
       for(int i=1;i<nums.size();i++){
        if(nums[i]==num){
            nums.erase(nums.begin()+i);
            i--;
        }
        if(nums[i]!=num){
            num=nums[i];
        }
       }
       return nums.size();
       
    }
};