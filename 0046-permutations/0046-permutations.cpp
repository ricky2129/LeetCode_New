class Solution {
private:
    // Recursive function to generate permutations
    void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
        // Base case: If we have processed all elements, add the permutation to the result
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Recursion: Try all possible swaps for the current index
        for (int i = index; i < nums.size(); i++) {
            // Swap the elements at index and i
            if (i > index && nums[i] == nums[index]) {
                continue; // Skip duplicates
            }
            swap(nums[index], nums[i]);
            // Recursively generate permutations for the remaining elements
            solve(nums, ans, index + 1);
            // Backtrack by swapping back to the original state
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index); // Start generating permutations from index 0
        return ans;
    }
};