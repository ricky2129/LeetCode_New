// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int arr[nums.size()];
        
        
//         for(int i=0;i<nums.size();i++){
//             arr[i]=0;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(arr[nums[i]]==0){
//                 arr[nums[i]] += 1;
//             }
//             else{
//                 return nums[i];
//             }
//         }
//         return 0;
//     }
// };
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num : nums){
            int idx=abs(num);
            if(nums[idx]<0){
                return idx;
            }
            nums[idx]=-nums[idx];

        }
        return 0;
    }
};