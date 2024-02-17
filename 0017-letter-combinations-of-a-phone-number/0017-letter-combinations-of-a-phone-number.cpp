class Solution {
public:
    void solve(string res, vector<string>& ans, string digits, int i, string mapping[]){
        if(i >= digits.length()){
            ans.push_back(res);
            return;
        }

        int index = digits[i] - '0';
        string val = mapping[index];
        for(int j = 0; j<val.length(); j++){
            res.push_back(val[j]);
            solve(res, ans, digits, i+1, mapping);
            res.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits){
        vector<string> ans;
        if(digits.length() == 0)    return ans;
        string res = "";
        string mapping[10] = {"", "", "abc" , "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(res, ans, digits, 0, mapping);
        return ans;
    }
};