class Solution {
public:

    int check(vector<int>& piles, int h,int mid){
        int ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=(piles[i]/mid);
            if(piles[i]%mid!=0){
                ans++;
            }
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int low=1;
        int high=piles[n-1];

        while(low<high){
            int mid= low + (high-low)/2;
            if(check(piles,h,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};