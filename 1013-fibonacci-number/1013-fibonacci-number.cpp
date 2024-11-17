class Solution {
public:
    int solve(int n){//recursive way
        //base case
       if(n==1 || n==0) {
        return n;
       }

       int ans =  solve(n-1) + solve(n-2);
       return ans;
    }
    //top-down approach(recursion + memoisation)
    int dpsolve(int n , vector<int> &dp){
        //base case
        if(n==1 || n==0){
            return n;
        }
        //3. check for existing values
        if(dp[n]!=-1){
            return dp[n];
        }
    //2.store in dp array
        dp[n]=dpsolve(n-1,dp) + dpsolve(n-2,dp);
        return dp[n];
    }
    
    int fib(int n) {
       int ans =solve(n);
    //    1.create dp array
       vector<int>dp(n+1,-1);
       int ans2=dpsolve(n , dp);
       return ans2;
    }
};