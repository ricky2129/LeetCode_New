class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            // Check if the current number is in the correct position or if it's out of bounds.
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++; // Only increment 'i' if no swap is needed or possible.
            }
        }

        // Check for the first missing positive by looking for the first index 'i'
        // where the value is not 'i + 1'.
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1; // Return the first missing positive integer.
            }
        }

        // If all positions from 1 to 'nums.size()' are occupied correctly, the answer
        // is 'nums.size() + 1'.
        return nums.size() + 1;
    }
};
