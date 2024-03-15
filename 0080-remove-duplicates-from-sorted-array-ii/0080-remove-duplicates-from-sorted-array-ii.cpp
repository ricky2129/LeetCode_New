#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1; // Count for the current element
        int i = 1;     // Index to track the position to be replaced

        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] == nums[j - 1]) {
                // Increment count for the same element
                count++;
            } else {
                // Reset count for a new element
                count = 1;
            }

            if (count <= 2) {
                // If count is less than or equal to 2, keep the element
                nums[i++] = nums[j];
            }
        }

        return i; // Return the length of the modified array
    }
};
