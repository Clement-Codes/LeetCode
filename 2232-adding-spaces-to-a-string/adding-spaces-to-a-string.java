class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder ss = new StringBuilder();
        int i = 0, j = 0;
        while (i < s.length() && j < spaces.length){
            if (i < spaces[j]){
                ss.append(s.charAt(i));
                i++;
            }
            else{
                ss.append(" ");
                j++;
            }
        }
        
        ss.append(s.substring(i, s.length()));
            
        return ss.toString();
    }
}