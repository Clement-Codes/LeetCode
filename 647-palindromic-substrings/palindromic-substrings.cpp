class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++){
            int l = i, r = i;
            while ( -1 < l && r < s.length() && s[l] == s[r] ){
                result++;
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while ( -1 < l && r < s.length() && s[l] == s[r] ){
                result++;
                l--;
                r++;
            }
        }
        return result;
    }
};