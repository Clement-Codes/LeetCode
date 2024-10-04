class Solution {
    public String longestPalindrome(String s) {
        String result = "";
        int resultLen = 0;
        for (int i  = 0; i < s.length(); i++){
            int l = i, r = i;
            while (0<=l && r < s.length() && s.charAt(l) == s.charAt(r)){
                if((r + 1) - l >= resultLen){
                    resultLen = (r + 1) - l;
                    result = s.substring(l, r + 1); 
                }
                l -= 1;
                r += 1;
            }
            l = i;
            r = i + 1;
            while (0<=l && r < s.length() && s.charAt(l) == s.charAt(r)){
                if((r + 1) - l >= resultLen){
                    resultLen = (r + 1) - l;
                    result = s.substring(l, r + 1); 
                }
                l -= 1;
                r += 1;
            }
        }
        return result;
    }
}