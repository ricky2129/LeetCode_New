class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26);
        for(auto c : s)freq[c - 'a']++;
        for(int indx = 0; indx < s.size(); indx++){
            if(freq[s[indx] - 'a'] == 1)return indx;
        }
        return -1;
    }
};