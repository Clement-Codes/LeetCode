class Solution {
public:
    bool isAlphaNum(char c){
        if ((int('A') <= int(c) && int(c) <= int('Z')) or (int('a') <= int(c) && int(c) <= int('z')) or (int('0') <= int(c) && int(c) <= int('9'))) return true;
        return false;
    }

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