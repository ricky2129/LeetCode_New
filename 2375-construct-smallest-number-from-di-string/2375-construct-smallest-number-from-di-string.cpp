class Solution {
public:
    string smallestNumber(string pattern) {
       string ans="";
       int n=pattern.size();
       stack<char> st;
       int i=0;
       char ch='1';
       st.push(ch);


       while(!st.empty()&&i<n){
           ch++;
           if(pattern[i]=='I'){
               while(!st.empty()){
                   ans+=st.top();
                   st.pop();
               }
               st.push(ch);
           }
           else{
               st.push(ch);
           }
           i++;
       } 

       while(!st.empty()){
           ans+=st.top();
           st.pop();
       }
       return ans;
    }
};