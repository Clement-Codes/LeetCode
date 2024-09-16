import java.util.HashMap;

class Solution {
    public int characterReplacement(String s, int k) {
        HashMap<Character, Integer> m = new HashMap<Character, Integer>();
        int maxf = 0;
        int result = 0;
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            if(m.containsKey(s.charAt(r))) m.put(s.charAt(r), m.get(s.charAt(r)) + 1);
            else m.put(s.charAt(r), 1);
            maxf = Math.max(maxf, m.get(s.charAt(r)));
            if((r-l+1) - maxf > k){
                m.put(s.charAt(l), m.get(s.charAt(l)) - 1);
                l += 1;
            }
            result = Math.max(result, r-l+1);
        }
        return result; 
    }
}