class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>freq(n+1,0);
        int ans=-1;
         
        for(int i=0;i<trust.size();i++){
            int c=trust[i][1];
            int d=trust[i][0];
            freq[c]+=1;
            freq[d]-=1;
        }
        for(int i=1;i<freq.size();i++){
            if(freq[i]==n-1) {
                ans= i;
            }
        }
        return ans;
    }
};