class Solution {
public:
    // void solveRE(vector<string>&ans,int n,int i,string &x){
    //     if(i>=x.size()){
    //         ans.push_back(x);
    //         return;
    //     }
    //     for(int j=i;j<n;j++){
    //         swap(x[i],x[j]);
    //         solveRE(ans,n,i+1,x);
    //         swap(x[i],x[j]);
    //     }
    // }
    string getPermutation(int n, int k) {
        // vector<string> ans;
        // string x="";
        // for(int i=1;i<=n;i++){
        //     x=x+to_string (i);
        // }
        // solveRE(ans,n,0,x);
        // sort(ans.begin(),ans.end());
        // string y=ans[k-1];
        // return y;
        int fact=1;
        vector<int>nums;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans="";
        k=k-1;
        while(true){
            ans+= to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0) break;
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};