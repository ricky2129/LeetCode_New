class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int len = INT_MAX;
        
        while (j < nums.size()) {
            sum += nums[j];
            
            while (i < nums.size() && sum >= target) {
                len = min(len, j - i + 1);
                sum -= nums[i];
                i++;
            }
            
            j++; // Move j forward
        }
        
        return len == INT_MAX ? 0 : len;
    }
};
