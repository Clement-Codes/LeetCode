class Solution {
    public boolean isLetterOrDigit(char c){
        if (((int)'A' <= (int)c && (int)c <= (int)'Z') || ((int)'a' <= (int)c && (int)c <= (int)'z') || ((int)'0' <= (int)c && (int)c <= (int)'9')) return true;
        return false;
    }
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j){
            while ((i < j) && !isLetterOrDigit(s.charAt(i))) i += 1;
            while ((i < j) && !Character.isLetterOrDigit(s.charAt(j))) j -= 1;
            if ( Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j)))return false;
            
            i += 1;
            j -= 1;
        }
        return true;
    }
}