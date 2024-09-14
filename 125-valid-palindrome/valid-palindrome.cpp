class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j){
            while ((i < j) && !isalnum(s[i])) i += 1;
            while ((i < j) && !isalnum(s[j])) j -= 1;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
};