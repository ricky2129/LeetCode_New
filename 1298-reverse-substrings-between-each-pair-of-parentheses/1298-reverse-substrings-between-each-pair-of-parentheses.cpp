class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st; // Use a stack to store characters
        for (int i = 0; i < s.size(); i++) { // Loop through the entire string
            if (s[i] == ')') {
                string revWord = "";
                // Pop characters until we find an opening parenthesis '('
                while (st.top() != '(') {
                    revWord += st.top() ;
                    cout<<revWord<<endl;
                    st.pop();
                }
                st.pop(); // Pop the '('
                // Push the reversed word back onto the stack
                for (char c : revWord) {
                    st.push(c);
                }
            } else {
                st.push(s[i]); // Push current character onto the stack
            }
        }

        string finalWord = "";
        // Pop all characters from the stack to form the final result
        while (!st.empty()) {
            finalWord = st.top() + finalWord;
            st.pop();
        }
    // reverse(finalWord.begin(),finalWord.end());
        return finalWord;
    }
};