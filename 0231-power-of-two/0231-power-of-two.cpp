class Solution {
public:
    
    bool isPowerOfTwo(int n) {
        // if(n==0) return false;
        // if (n==1) return true;
         
        // if(n&1){
        //      return false;
        //  }
        //  else{
        //      return isPowerOfTwo(n/2);
        //  }

          return n<=0 ? false : !(n&(n-1));
    }
};