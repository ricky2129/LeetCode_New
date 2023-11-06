class Solution {
public:
    int romanToInt(string s) {
         string romanSymbols []={"M" ,"CM" , "D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int values []={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int ans=0;
        int pos=0;
        string x;
        string xy;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<13;j++){
                x=s[i];
                xy=s.substr(i,2);
                if(xy==romanSymbols[j]){
                    pos=j;
                    i++;
                }
                if(x==romanSymbols[j]){
                    pos=j;
                }
            }
            ans=ans+values[pos];

        }
        return ans;
    }
};