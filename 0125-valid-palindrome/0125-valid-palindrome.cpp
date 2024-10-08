class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            // Skip non-alphanumeric characters from the front
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            // Skip non-alphanumeric characters from the back
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            // Compare characters in a case-insensitive manner
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            // Move to the next characters
            i++;
            j--;
        }

        return true;
    }
};