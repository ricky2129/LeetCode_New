#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solveRE(int i, vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(ans); // Found a valid combination
            return;
        }
        if (i == candidates.size() || target < 0) {
            return; // Base case: no more candidates or target exceeded
        }

        for (int j = i; j < candidates.size(); ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue; // Skip duplicates
            }
            ans.push_back(candidates[j]); // Include the current candidate
            solveRE(j + 1, candidates, target - candidates[j], ans, result); // Recurse with the next candidate
            ans.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
        solveRE(0, candidates, target, ans, result);
        return result;
    }
};
