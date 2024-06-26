class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;  // Stack to keep characters and their counts

        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;  // Increment the count of the top element
                if (st.top().second == k) {
                    st.pop();  // Remove the element if count reaches k
                }
            } else {
                st.push({c, 1});  // Push new character with count 1
            }
        }

        string result;
        while (!st.empty()) {
            result.append(st.top().second, st.top().first);  // Append characters to result
            st.pop();
        }
        reverse(result.begin(), result.end());  // Reverse to correct the order
        return result;
    }
};