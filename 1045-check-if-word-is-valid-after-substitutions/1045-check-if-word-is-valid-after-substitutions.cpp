class Solution {
public:
    bool isValid(string s) {

        if(s[0]!='a') return false;
        stack<char>st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                st.push(s[i]);
            }

            else if(s[i]=='b'){
                if(!st.empty() && st.top()=='a'){
                    st.push(s[i]);
                }
                else{
                    return false;
                }
            }
            else{
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    if(!st.empty() && st.top()=='a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
        
    }
};