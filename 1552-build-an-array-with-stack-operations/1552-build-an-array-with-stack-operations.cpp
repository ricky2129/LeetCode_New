class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;
        int targetIndex = 0;

        for (int i = 1; i <= n; i++) {
            if (targetIndex >= target.size()) {
                break;  // Stop if all target elements are processed
            }

            st.push(i);
            ans.push_back("Push");

            if (target[targetIndex] == i) {
                targetIndex++;  // Move to the next target element
            } else {
                st.pop();
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};