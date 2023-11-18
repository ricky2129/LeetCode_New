class Solution {
public:
    int lengthOfLastWord(string s) {
       int n=s.length()-1;
       string word;
    std::istringstream iss(s);
      for(int i=0;i<=n;i++){
          iss >> word;
      }
      return word.length();
    }
};