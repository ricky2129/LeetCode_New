class Solution {
public:
   void dfs(int idx,string s , vector<string>&res)
   {
       if(idx==s.size())
       {
           res.push_back(s);
       }
       if(s[idx]>='0'&&s[idx]<='9')
       {
           dfs(idx+1,s,res);
       }
       else if (s[idx]>='A'&&s[idx]<='Z')
       {
           dfs(idx+1,s,res);
           s[idx]=s[idx]+32;
           dfs(idx+1,s,res);
       }
       else if (s[idx]>='a'&&s[idx]<='z')
       {
           dfs(idx+1,s,res);
           s[idx]=s[idx]-32;
           dfs(idx+1,s,res);
       }

   }

    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        dfs(0,s,res);
        return res;
    }
};