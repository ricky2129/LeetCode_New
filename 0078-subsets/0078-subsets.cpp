class Solution {
public:
    void subsetRE(vector<vector<int>> &subsets, vector<int> &nums, vector<int> &current, int i) {
        if (i == nums.size()) {
            subsets.push_back(current); // Add the current subset
            return;
        }

        // Exclude the current element and recurse
        subsetRE(subsets, nums, current, i + 1);

        // Include the current element and recurse
        current.push_back(nums[i]);
        subsetRE(subsets, nums, current, i + 1);

        // Backtrack: Remove the last element before going up the recursion tree
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> current; // Temporary vector to store the current subset
        subsetRE(subsets, nums, current, 0); // Start recursion with index 0
        return subsets;
    }
};
