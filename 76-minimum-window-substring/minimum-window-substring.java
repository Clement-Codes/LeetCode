import java.util.HashMap;

class Solution {
    public String minWindow(String s, String t) {
        if(t == "" || s.length() < t.length()) return "";

        HashMap<Character, Integer> history = new HashMap<Character, Integer>();
        HashMap<Character, Integer> window  = new HashMap<Character, Integer>();

        for(Character c: t.toCharArray()){
            if(history.containsKey(c)) history.put(c, history.get(c) + 1);
            else history.put(c, 1);
        }

        int left = 0;
        int resultLeft = -1;
        int resultRight = -1;
        int resultLength = Integer.MAX_VALUE;
        int required = history.size();
        int having = 0;

        for(int right = 0; right < s.length(); right++){
            Character c = s.charAt(right);
            if(window.containsKey(c)) window.put(c, window.get(c) + 1);
            else window.put(c, 1);

            if(history.containsKey(c) && (int)history.get(c) == (int)window.get(c)) having += 1;
            
            
            while(having == required){ 
                if((right - left + 1) < resultLength){
                    resultRight = right;
                    resultLeft = left;
                    resultLength = right - left + 1;
                }
                c = s.charAt(left);
                window.put(c, window.get(c) - 1);

                if(history.containsKey(c) && history.get(c) > window.get(c)) having -= 1;
                left += 1;
            }
        }
        
        if (resultLength != Integer.MAX_VALUE) return s.substring(resultLeft, resultRight + 1);
        else return "";
    }
}