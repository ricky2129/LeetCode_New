class Solution {
public:
    string backspace(string x){
        stack<char>st;
        string y="";
       for (char c : x) {
            if (c == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }

        while(!st.empty()){
            char n=st.top();
            y=n+y;
            st.pop();
        }
        return y;

    }
    bool backspaceCompare(string s, string t) {
        cout<<backspace(s)<<endl;
        cout<<backspace(t)<<endl;
        return(backspace(s)==backspace(t));

    }
};