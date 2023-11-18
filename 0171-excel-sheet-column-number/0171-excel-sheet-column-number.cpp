class Solution {
public:
    int titleToNumber(string columnTitle) {
        int total=0;
        for(int i=0;i<columnTitle.length();i++){
            total=total*26 +(columnTitle[i]-'A' +1);
        }
        return total;
    }
};