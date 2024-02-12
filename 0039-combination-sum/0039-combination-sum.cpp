class Solution {
public:
    void solveRE(int i, vector<int>& candidates, int target, int sum, vector<int>& ans, vector<vector<int>>& result) {
        // Base case: when the current sum equals the target, add the combination to the result
        if (sum == target) {
            result.push_back(ans);
            return;
        }
        // Stop the recursion if the sum exceeds the target or if we've considered all candidates
        if (sum > target || i == candidates.size()) {
            return;
        }

        // Include the current candidate and recurse
        ans.push_back(candidates[i]);
        solveRE(i, candidates, target, sum + candidates[i], ans, result); // Note: We don't increment i to allow using the same number multiple times

        // Exclude the current candidate and recurse
        ans.pop_back(); // Backtrack
        solveRE(i + 1, candidates, target, sum, ans, result); // Move to the next candidate
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        solveRE(0, candidates, target, 0, ans, result); // Start recursion with the first candidate
        return result;
    }
};
