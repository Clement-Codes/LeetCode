import java.util.HashMap;

class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> h_s = new HashMap<Character, Integer>();
        HashMap<Character, Integer> h_t = new HashMap<Character, Integer>();
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++){
            if (h_s.get(s.charAt(i))!=null){
                h_s.put(s.charAt(i), h_s.get(s.charAt(i)) + 1);
            }else{
                h_s.put(s.charAt(i), 1);
            }
            if (h_t.get(t.charAt(i))!= null){
                h_t.put(t.charAt(i), h_t.get(t.charAt(i)) + 1);
            }else{
                h_t.put(t.charAt(i), 1);
            }
        }
        for(char k: h_s.keySet()){
            if(h_t.get(k) == null || !h_s.get(k).equals(h_t.get(k))){
                return false;
            }
        }
        return true;
    }
}