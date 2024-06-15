class Solution {
public:
    int scoreOfParentheses(string s) {
        int count =0;
        stack<int>st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(-1);
            }
            else{
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int val=0;
                    while(st.top()!=-1){
                        val+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*val);
                }
            }
        }

        while(st.size()>0){
            count+=st.top();
            st.pop();

        }

        return count;
    }
};