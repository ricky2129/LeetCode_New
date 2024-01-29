class Solution {
public:
    // void findSubsequence(string s,string t,int i,string output,vector<string>& v){
    //     if(i==t.length()){
    //         v.push_back(output);
    // return;

    //     }
        
    //     //excluding case
    //     findSubsequence( s,t,i+1,output,v);
    //     //including 
    //     findSubsequence(s,t,i+1,output+t[i],v);


    // }




//         int i =0;
//         string output="";
//         vector<string>v;

//         findSubsequence(s,t,i,output,v);

//         for(auto val: v) {
//     // cout << val << " " ; 
//     if(val==s){
//         return true;
//     }
//   }
//   return false;

    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(j<t.length()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else
            {    j++;
            }
            
        }
        return i==s.length()?true:false;


     
    }
};