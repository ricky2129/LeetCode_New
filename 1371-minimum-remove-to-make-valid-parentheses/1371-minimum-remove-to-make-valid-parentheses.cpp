class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
unordered_set<int> toRemove; // To keep track of indices to remove

for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
        st.push(i); // Push the index of '(' onto the stack
    } else if (s[i] == ')') {
        if (!st.empty()) {
            st.pop(); // Found a matching '(' for the current ')'
        } else {
            toRemove.insert(i); // No matching '(', mark this ')' for removal
        }
    }
}

// Add remaining unmatched '(' to the set
while (!st.empty()) {
    toRemove.insert(st.top());
    st.pop();
}

// Build the result string
string result;
for (int i = 0; i < s.size(); i++) {
    if (toRemove.find(i) == toRemove.end()) {
        result += s[i];
    }
}

// Return the result
return result;
        while(!st.empty()){
            cout<<st.top()<<endl;
            st.pop();
        }

        return s;
        
    }
};