class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum=0;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a+b;
                st.push(b);
                st.push(a);
                st.push(c);
            }
            else if(operations[i]=="D"){
                int x=st.top();
                int y=2*x;
                st.push(y);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }

        return sum;
    }
};