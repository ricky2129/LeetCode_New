class Solution {
public:
    void solveRE(vector<int>&v,int &n,int &ans,int currNum){
        //base case
        if(currNum==n+1){
            for(int i=1;i<n+1;i++){
                cout<<v[i]<<" ";
            }
            ++ans;
            return;
        }



        //one case solve
        for(int i=1;i<=n;++i){
            if(v[i]==0 &&(currNum % i==0 || i%currNum==0)){
                v[i]=currNum;
                solveRE(v,n,ans,currNum+1);
                v[i]=0;//backtracking
            }
        }

    }
    int countArrangement(int n) {
        vector<int> v(n+1);
        int ans=0;
        solveRE(v,n,ans,1);
        return ans;
        
    }
};