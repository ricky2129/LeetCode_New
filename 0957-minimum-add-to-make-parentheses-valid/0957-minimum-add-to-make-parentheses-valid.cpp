#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;  // Use char instead of int to store the characters

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }

        return st.size(); // The size of the stack represents the count of unbalanced parentheses
    }
};
