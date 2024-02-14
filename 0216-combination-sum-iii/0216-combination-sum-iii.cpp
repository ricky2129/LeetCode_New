class Solution {
public:
    void solveRE(int i, int n, int k, vector<int>& ans, vector<vector<int>>& result) {
        if (n == 0 && k == 0) {
            // If the sum is reached and we've used exactly k numbers, add the combination
            result.push_back(ans);
            return;
        }
        if (n < 0 || k < 0 || i > 9) {
            // If the sum is exceeded, we've used more than k numbers, or exceeded the number range, return
            return;
        }

        for (int j = i; j <= 9; ++j) { // Iterate through numbers 1 to 9
            ans.push_back(j); // Include the current number
            solveRE(j + 1, n - j, k - 1, ans, result); // Recurse with the next number, decreased sum and one less number to find
            ans.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ans;
        solveRE(1, n, k, ans, result); // Start recursion with the number 1
        return result;
    }
};
