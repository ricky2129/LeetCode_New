class Solution {
public:
    double myPow(double x, int n) {
    //     if(n==0) return 1;
    //     double ans=1;

    //     if(n<0){
    //         long long y=abs(n);
    //         for(long long i=1;i<=y;i++){
    //         ans=ans*x;
    //         }
    //         ans=1/ans;

    //     }
    //     else{
    //         for(long long i=1;i<=n;i++){
    //         ans=ans*x;
    //         }
    //     }
        
    // return ans;

    double ans=1;

    if(n<0){
        n=abs(n);
        while(n>0){
        if(n&1){
            ans=ans*x;
        }
        x=x*x;
        n>>=1;
    }
    ans=1/ans;
    }
    while(n>0){
        if(n&1){
            ans=ans*x;
        }
        x=x*x;
        n>>=1;
    }
    return ans;
    }
};