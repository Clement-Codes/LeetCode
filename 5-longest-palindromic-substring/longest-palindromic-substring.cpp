class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int resultLen = 0;
        for (int i  = 0; i < s.length(); i++){
            int l = i, r = i;
            while (0<=l && r < s.length() && s[l] == s[r]){
                if((r + 1) - l >= resultLen){
                    resultLen = (r + 1) - l;
                    result = s.substr(l, (r + 1) - l); 
                }
                l -= 1;
                r += 1;
            }
            l = i, r = i + 1;
            while (0<=l && r < s.length() && s[l] == s[r]){
                if((r + 1) - l >= resultLen){
                    resultLen = (r + 1) - l;
                    result = s.substr(l, (r + 1) - l); 
                }
                l -= 1;
                r += 1;
            }
        }
        return result;
    }
};