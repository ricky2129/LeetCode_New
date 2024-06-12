class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < n && nums[left] == sorted_nums[left]) left++;
        while (right >= 0 && nums[right] == sorted_nums[right]) right--;

        return right > left ? right - left + 1 : 0;
    }
};