class Solution {
    public String makeFancyString(String s) {
        int streak = 1;
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); i++){
            if (i > 1 && s.charAt(i) == result.charAt(result.length() - 1) && result.charAt(result.length() - 1) == result.charAt(result.length() - 2)) continue;
            result.append(s.charAt(i));
        }
        return result.toString();
    }
}